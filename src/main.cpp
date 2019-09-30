#include <gflags/gflags.h>
#include <grpc++/grpc++.h>
//#include <spdlog/spdlog.h>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <iostream>

#include "protobuf/faiss.grpc.pb.h"
#include "faiss_server.h"

DEFINE_string(host, "0.0.0.0", "host of faiss server");
DEFINE_string(port, "8080", "port of faiss server");
DEFINE_string(file_path, "", "index file name");
DEFINE_uint64(top_k, 10, "default number of neighbor");
DEFINE_bool(on_cpu, false, "run on CPU or not");

int main(int argc, char* argv[]) {
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  std::string address = FLAGS_host + ":" + FLAGS_port;
  auto logger = spdlog::stdout_color_mt("console");
  FaissServer fsrv(logger, FLAGS_top_k, FLAGS_file_path.c_str(), FLAGS_on_cpu);
  grpc::ServerBuilder builder;
  builder.AddListeningPort(address, grpc::InsecureServerCredentials());
  builder.RegisterService(&fsrv);
  std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
  logger->info("Server run on {0}", address);
  server->Wait();
  return 0;
}
