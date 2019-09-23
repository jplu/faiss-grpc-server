FROM jplu/faiss:1.5.3-gpu

RUN apt update && apt install -y protobuf-compiler-grpc libssl-dev cmake libgrpc++-dev protobuf-compiler libspdlog-dev libgrpc-dev libgflags-dev libgtest-dev libc-ares-dev libprotobuf-dev

ENV CPATH /usr/local/cuda/include

WORKDIR /builder

COPY src src
COPY CMakeLists.txt .

RUN ls && mkdir build && mkdir /usr/lib/x86_64-linux-gnu/cmake/grpc

COPY grpc-config.cmake /usr/lib/x86_64-linux-gnu/cmake/grpc/

RUN cd build && cmake .. && make

ENTRYPOINT ["/builder/build/bin/faiss_server"]

CMD ["--help"]
