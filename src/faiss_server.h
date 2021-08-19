#ifndef FAISS_SERVER_H_
#define FAISS_SERVER_H_

#include <filesystem>

#include "faiss/gpu/StandardGpuResources.h"
#include "faiss/gpu/GpuIndexFlat.h"
#include "faiss/gpu/GpuAutoTune.h"
#include "faiss/gpu/GpuCloner.h"
#include "faiss/gpu/GpuClonerOptions.h"
#include "faiss/IndexFlat.h"
#include "faiss/IVFlib.h"
#include "faiss/IndexIVF.h"
#include "faiss/index_io.h"
#include "faiss/impl/AuxIndexStructures.h"
#include <grpc++/grpc++.h>
#include <spdlog/spdlog.h>

#include "protobuf/faiss.grpc.pb.h"
#include "metrics_reporter.h"


class FaissServer final : public faiss::FaissService::Service {
    public:
        FaissServer(const std::shared_ptr<spdlog::logger>& logger, const uint& default_top_k, const char* file_path, bool onCPU, const uint& nprobe);

        grpc::Status Search(grpc::ServerContext* context, const faiss::SearchRequest* request, faiss::SearchResponse* response) override;

        grpc::Status SearchById(grpc::ServerContext* context, const faiss::SearchByIdRequest* request, faiss::SearchByIdResponse* response) override;

        MetricsReporter* MetricReporter() const { return reporter_.get(); }

    private:
        const std::shared_ptr<spdlog::logger>& logger_;
        std::shared_ptr<MetricsReporter> reporter_;
        const uint& default_top_k_;
        //const uint& nprobe_;
        //int ngpus = 0;
        std::shared_ptr<faiss::Index> faissIndex = nullptr;
        //std::vector<faiss::gpu::GpuResourcesProvider *> res;
        //std::vector<int> devs;
        //faiss::gpu::GpuMultipleClonerOptions *options = new faiss::gpu::GpuMultipleClonerOptions();
};

#endif  // FAISS_SERVER_H_
