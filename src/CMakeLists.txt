project(faiss_server)
cmake_minimum_required (VERSION 3.18)
cmake_policy(SET CMP0003 NEW)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

# Find 3rd parties
find_package(gflags REQUIRED)
find_package(spdlog REQUIRED)
find_package(Protobuf REQUIRED)
find_package(GRPC REQUIRED)
find_package(prometheus-cpp CONFIG REQUIRED)

# Faiss Server
add_executable(faiss_server
    main.cpp faiss_server.cpp metrics.cpp metrics_reporter.cpp
    protobuf/faiss.grpc.pb.cc protobuf/faiss.pb.cc)

target_link_libraries(faiss_server
    faiss gomp mkl_intel_lp64 gflags spdlog::spdlog
    protobuf::libprotobuf prometheus-cpp::core prometheus-cpp::pull
    grpc++_unsecure)
