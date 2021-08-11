#include <gflags/gflags.h>
#include <grpc++/grpc++.h>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <iostream>
#include "mkl/mkl_service.h"
#include <omp.h>

#include "protobuf/faiss.grpc.pb.h"
#include "faiss_server.h"

DEFINE_string(host, "0.0.0.0", "host of faiss server");
DEFINE_string(port, "8080", "port of faiss server");
DEFINE_string(file_path, "", "index file name");
DEFINE_uint64(top_k, 10, "default number of neighbor");
DEFINE_bool(on_cpu, false, "run on CPU or not");
DEFINE_uint64(nprobe, 256, "nprobe > 0 && nprobe <= nlist");

int main(int argc, char* argv[]) {
  mkl_set_dynamic(0);
  mkl_set_num_threads(omp_get_max_threads());
  omp_set_num_threads(omp_get_max_threads());
  const grpc::string kHealthyService("healthy_service");
  grpc::EnableDefaultHealthCheckService(true);
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  std::string address = FLAGS_host + ":" + FLAGS_port;
  auto logger = spdlog::stdout_color_mt("console");
  logger->info("Set MKL to {0} threads", omp_get_max_threads());
  FaissServer fsrv(logger, FLAGS_top_k, FLAGS_file_path.c_str(), FLAGS_on_cpu, FLAGS_nprobe);
  grpc::ServerBuilder builder;
  builder.AddListeningPort(address, grpc::InsecureServerCredentials());
  builder.RegisterService(&fsrv);
  std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
  grpc::HealthCheckServiceInterface* service = server->GetHealthCheckService();
  service->SetServingStatus(kHealthyService, true);
  logger->info("Server run on {0}", address);
  server->Wait();
  return 0;
}
