#include <faiss/impl/FaissException.h>

#include "faiss_server.h"

FaissServer::FaissServer(const std::shared_ptr<spdlog::logger>& logger,
                         const uint& default_top_k,
                         const char* file_path,
                         bool onCPU,
                         const uint& nprobe) : logger_(logger), default_top_k_(default_top_k) {
    try {
        this->faissIndex.reset(faiss::read_index(file_path));
        
        faiss::IndexIVF* ivf = faiss::ivflib::extract_index_ivf(this->faissIndex.get());
        
        ivf->nprobe = nprobe;
        ivf->parallel_mode = 1;

        if (!onCPU) {
            std::vector<faiss::gpu::GpuResourcesProvider *> res;
            std::vector<int> devs;

            for (int i = 0; i < faiss::gpu::getNumDevices(); i++) {
                res.push_back(new faiss::gpu::StandardGpuResources);
                devs.push_back(i);
            }

            faiss::gpu::GpuMultipleClonerOptions *options = new faiss::gpu::GpuMultipleClonerOptions();
      
            options->indicesOptions = faiss::gpu::INDICES_64_BIT;
            options->useFloat16CoarseQuantizer = false;
            options->useFloat16 = true;
            options->usePrecomputed = false;
            options->reserveVecs = 0;
            options->storeTransposed = false;
            options->verbose = true;
            options->shard = true;
            
            this->faissIndex.reset(faiss::gpu::index_cpu_to_gpu_multiple(res, devs, this->faissIndex.get(), options));
        }

        MetricsReporter::Create(std::filesystem::path(file_path).filename(), &this->reporter_);
    } catch (faiss::FaissException& fe) {
        this->logger_->error("Failed to read index: {}", fe.msg);
        
        std::exit(1);
    } catch (std::exception& e) {
        this->logger_->error("Failed to read index: {}", e.what());
        
        std::exit(1);
    }
}

grpc::Status FaissServer::Search(grpc::ServerContext* context, const faiss::SearchRequest* request, faiss::SearchResponse* response) {
    auto top_k = request->top_k();

    if (top_k <= 0) {
        top_k = this->default_top_k_;
    }

    if (!request->has_vector()) {
        this->MetricReporter()->MetricInferenceFailure().Increment(1);

        return grpc::Status(grpc::StatusCode::INVALID_ARGUMENT, "Not found vector in request");
    }

    if (request->vector().float_val_size() != this->faissIndex->d) {
        this->MetricReporter()->MetricInferenceFailure().Increment(1);

        this->logger_->error("Given vector is invalid size: expect={}, actual={}", this->faissIndex->d, request->vector().float_val_size());
        
        return grpc::Status(grpc::StatusCode::INVALID_ARGUMENT, "Given vector is invalid size");
    }

    auto std_vector = std::vector<float>(request->vector().float_val().begin(), request->vector().float_val().end());
    
    this->logger_->info("Search: top_k={}, size={}", top_k, request->vector().float_val_size());

    std::vector<long> indices(top_k);
    std::vector<float> dist(top_k);

    try {
        this->faissIndex->search(1, std_vector.data(), top_k, dist.data(), indices.data());
    } catch (std::exception& e) {
        this->MetricReporter()->MetricInferenceFailure().Increment(1);

        this->logger_->error("Failed to search index: {}", e.what());
        
        return grpc::Status(grpc::StatusCode::INTERNAL, "Failed to search index");
    }

    for (int i = 0; i < top_k; i++) {
        auto neighbor = response->add_neighbors();
    
        neighbor->set_id(indices[i]);
        neighbor->set_score(dist[i]);
    }

    this->MetricReporter()->MetricInferenceSuccess().Increment(1);

    return grpc::Status::OK;
}

grpc::Status FaissServer::SearchById(grpc::ServerContext* context, const faiss::SearchByIdRequest* request, faiss::SearchByIdResponse* response) {
    auto top_k = request->top_k();
  
    if (top_k <= 0) {
        top_k = this->default_top_k_;
    }

    this->logger_->info("SearchById: top_k={}, request_id={}", top_k, request->id());

    std::vector<float> request_vector(this->faissIndex->d);

    try {
        this->faissIndex->reconstruct(request->id(), request_vector.data());
    } catch (std::exception& e) {
        this->MetricReporter()->MetricInferenceFailure().Increment(1);

        this->logger_->error("Failed to reconstruct for request id: {}", e.what());
    
        return grpc::Status(grpc::StatusCode::INTERNAL, "Failed to reconstruct for request id");
    }

    // exclude request id
    top_k++;

    std::vector<long> indices(top_k);
    std::vector<float> dist(top_k);

    try {
        this->faissIndex->search(1, request_vector.data(), top_k, dist.data(), indices.data());
    } catch (std::exception& e) {
        this->MetricReporter()->MetricInferenceFailure().Increment(1);

        this->logger_->error("Failed to search index: {}", e.what());
        
        return grpc::Status(grpc::StatusCode::INTERNAL, "Failed to search index");
    }

    for (int i = 1; i < top_k; i++) {
        auto neighbor = response->add_neighbors();
    
        neighbor->set_id(indices[i]);
        neighbor->set_score(dist[i]);
    }

    this->MetricReporter()->MetricInferenceSuccess().Increment(1);

    return grpc::Status::OK;
}
