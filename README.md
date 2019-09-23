# faiss-grpc-server

gRPC server over a FAISS index.

## Requirements
To install the required tools on Ubuntu, run the following command line:
```
apt update
apt install -y protobuf-compiler-grpc libssl-dev cmake libgrpc++-dev protobuf-compiler libspdlog-dev libgrpc-dev libgflags-dev libgtest-dev libc-ares-dev libprotobuf-dev
```

## Installation from source
To compile and install from source, run the following command lines:

```
git clone https://github.com/jplu/faiss-grpc-server
cd faiss-grpc-server
make cppclient
```

Then use CMake:

```
mkdir build; cd build
cmake ..
make
```

## Build as docker image:
To build the Docker image, run the folloging command line:

```
$ docker build -t faiss-server .
```

## Run FAISS server
To run FAISS server, write the following command line:
```
./build/bin/faiss_server -file_path <faiss_index_file>
```

## Run FAISS server from Docker
To create a container from the Docker image, run the following command line:
```
docker run -p 8080:8080 -v <folder_containing_the_index>:/tmp faiss-server -file_path /tmp/<faiss_index_file>
```

## Create the Python and Go clients
In order to create the Python and Go gRPC clients, run the following command lines:
```
make pyclient
make goclient
```

## Usage
```
faiss_server:
    -file_path (index file name) type: string default: ""
    -host (host of faiss server) type: string default: "0.0.0.0"
    -port (port of faiss server) type: string default: "8080"
    -top_k (default number of neighbor) type: uint64 default: 10
```
