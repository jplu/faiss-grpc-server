#include <faiss/FaissException.h>

#include "faiss_server.h"

FaissServer::FaissServer(const std::shared_ptr<logger>& logger,
                                   const uint& default_top_k,
                                   const char* file_path,
                                   bool onCPU)
    : logger_(logger), default_top_k_(default_top_k) {
  try {
    faissIndex.reset(faiss::read_index(file_path));
    
    is_trained = faissIndex->is_trained;
    ntotal = faissIndex->ntotal;
    dim = 512;

    if (!onCPU) {
      ngpus = faiss::gpu::getNumDevices();
      for (int i = 0; i < ngpus; i++) {
          res.push_back(new faiss::gpu::StandardGpuResources);
          devs.push_back(i);
      }
      options->indicesOptions = faiss::gpu::INDICES_64_BIT;
      options->useFloat16CoarseQuantizer = false;
      options->useFloat16 = false;
      options->usePrecomputed = false;
      options->reserveVecs = 0;
      options->storeTransposed = false;
      options->verbose = true;
      faissIndex.reset(faiss::gpu::index_cpu_to_gpu_multiple(res, devs, faissIndex.get(), options));
    }
  } catch (faiss::FaissException& fe) {
    logger_->error("Failed to read index: {}", fe.msg);
    std::exit(1);
  } catch (std::exception& e) {
    logger_->error("Failed to read index: {}", e.what());
    std::exit(1);
  }
}

grpc::Status FaissServer::Heartbeat(
    grpc::ServerContext* context, const ::google::protobuf::Empty* request,
    HeartbeatResponse* response) {
  logger_->info("Heartbeat");
  response->set_message("OK");
  return grpc::Status::OK;
}
