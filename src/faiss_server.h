#ifndef FAISS_SERVER_H_
#define FAISS_SERVER_H_

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

using faiss::FaissService;
using faiss::SearchByIdRequest;
using faiss::SearchByIdResponse;
using faiss::SearchRequest;
using faiss::SearchResponse;

using spdlog::logger;
using namespace faiss;
using namespace faiss::gpu;

class FaissServer final : public FaissService::Service {
 public:
  int dim;
  long ntotal;
  bool is_trained;
  FaissServer(const std::shared_ptr<logger>& logger,
              const uint& default_top_k, const char* file_path, bool onCPU);

  grpc::Status Search(grpc::ServerContext* context,
                      const SearchRequest* request,
                      SearchResponse* response) override;

  grpc::Status SearchById(grpc::ServerContext* context,
                          const faiss::SearchByIdRequest* request,
                          faiss::SearchByIdResponse* response) override;

 private:
  const std::shared_ptr<logger>& logger_;
  const uint& default_top_k_;
  int ngpus = 0;
  std::shared_ptr<faiss::Index> faissIndex = nullptr;
  std::vector<faiss::gpu::GpuResourcesProvider *> res;
  std::vector<int> devs;
  faiss::gpu::GpuMultipleClonerOptions *options = new faiss::gpu::GpuMultipleClonerOptions();
};

#endif  // FAISS_SERVER_H_
