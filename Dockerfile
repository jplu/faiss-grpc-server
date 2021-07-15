FROM nvidia/cuda:11.3.1-devel-ubuntu20.04 AS builder

RUN echo 'debconf debconf/frontend select Noninteractive' | debconf-set-selections

RUN apt update \
    && apt install wget -y \
    && wget https://github.com/Kitware/CMake/releases/download/v3.20.5/cmake-3.20.5-Linux-x86_64.sh -q -O /tmp/cmake-install.sh \
    && chmod u+x /tmp/cmake-install.sh \
    && mkdir /usr/bin/cmake \
    && /tmp/cmake-install.sh --skip-license --prefix=/usr/bin/cmake \
    && rm /tmp/cmake-install.sh

ENV PATH="/usr/bin/cmake/bin:${PATH}"

RUN apt install intel-mkl-full protobuf-compiler-grpc libssl-dev libgrpc++-dev protobuf-compiler libspdlog-dev libgrpc-dev libgflags-dev libgtest-dev libc-ares-dev libprotobuf-dev git -y -q

RUN git clone https://github.com/facebookresearch/faiss \
    && cd /faiss \
    && cmake -DCMAKE_INSTALL_PREFIX=/usr -DFAISS_ENABLE_PYTHON=OFF -DBUILD_SHARED_LIBS=ON -DCMAKE_BUILD_TYPE=Release -DFAISS_OPT_LEVEL=avx2 -B build . \
    && make -C build -j faiss \
    && make -C build install \
    && rm -rf /faiss

ENV CPATH="/usr/local/cuda-11.3/targets/x86_64-linux/include:${CPATH}"

RUN git clone https://github.com/jplu/faiss-grpc-server.git \
    && cd /faiss-grpc-server \
    && make cppclient \
    && mkdir /usr/lib/x86_64-linux-gnu/cmake/grpc \
    && cp grpc-config.cmake /usr/lib/x86_64-linux-gnu/cmake/grpc/ \
    && mkdir build \
    && cd build \
    && cmake .. \
    && make

FROM nvidia/cuda:11.3.1-runtime-ubuntu20.04

COPY --from=builder /faiss-grpc-server/build/bin/faiss_server /home/

COPY --from=builder /usr/lib/x86_64-linux-gnu/libfaiss.so /usr/lib/x86_64-linux-gnu/

RUN echo 'debconf debconf/frontend select Noninteractive' | debconf-set-selections \
    && apt update \
    && apt install intel-mkl libgflags2.2 libspdlog1 libprotobuf17 libgrpc++1 wget -y -q \
    && GRPC_HEALTH_PROBE_VERSION=v0.3.1 \
    && wget -qO/bin/grpc_health_probe https://github.com/grpc-ecosystem/grpc-health-probe/releases/download/${GRPC_HEALTH_PROBE_VERSION}/grpc_health_probe-linux-amd64 \
    && chmod +x /bin/grpc_health_probe

WORKDIR /home

ENTRYPOINT ["./faiss_server"]

CMD ["--help"]
