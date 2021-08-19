project(faiss-server)
cmake_minimum_required(VERSION 3.18)
include(ExternalProject)

ExternalProject_Add(prometheus-cpp
  PREFIX prometheus-cpp
  URL "https://github.com/jupp0r/prometheus-cpp/archive/v0.12.3.tar.gz"
  SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/prometheus-cpp/src/prometheus-cpp"
  CMAKE_CACHE_ARGS
    -DENABLE_PUSH:BOOL=OFF
    -DENABLE_PULL:BOOL=ON
    -DENABLE_TESTING:BOOL=OFF
    -DUSE_THIRDPARTY_LIBRARIES:BOOL=OFF
    -DCMAKE_POSITION_INDEPENDENT_CODE:BOOL=ON
    -DCMAKE_BUILD_TYPE:STRING=RELEASE
    -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_CURRENT_SOURCE_DIR}/prometheus-cpp
)

# faiss-server
ExternalProject_Add(faiss-server
  PREFIX faiss-server
  SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src"
  BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/bin"
  INSTALL_COMMAND ""
  CMAKE_CACHE_ARGS
        -Dprometheus-cpp_DIR:PATH=${CMAKE_CURRENT_SOURCE_DIR}/prometheus-cpp/lib/cmake/prometheus-cpp
  DEPENDS prometheus-cpp
)
