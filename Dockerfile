FROM nvidia/cuda:11.3.1-devel-ubuntu20.04 AS builder

SHELL ["/bin/bash", "-c"]

RUN echo 'debconf debconf/frontend select Noninteractive' | debconf-set-selections

RUN apt update \
    && apt install wget -y \
    && wget https://github.com/Kitware/CMake/releases/download/v3.20.5/cmake-3.20.5-Linux-x86_64.sh -q -O /tmp/cmake-install.sh \
    && chmod u+x /tmp/cmake-install.sh \
    && mkdir /usr/bin/cmake \
    && /tmp/cmake-install.sh --skip-license --prefix=/usr/bin/cmake \
    && rm /tmp/cmake-install.sh

ENV PATH="/usr/bin/cmake/bin:${PATH}"

RUN apt install git -y \
    && git clone --recurse-submodules -b v1.30.2 https://github.com/grpc/grpc \
    && cd grpc \
    && mkdir -p cmake/build \
    && pushd cmake/build \
    && cmake -DgRPC_INSTALL=ON -DBUILD_SHARED_LIBS=ON -DgRPC_BUILD_TESTS=OFF -DCMAKE_INSTALL_PREFIX=/usr ../.. \
    && make -j \
    && make install \
    && popd \
    && mkdir -p third_party/abseil-cpp/cmake/build \
    && pushd third_party/abseil-cpp/cmake/build \
    && cmake -DCMAKE_INSTALL_PREFIX=/usr/local -DCMAKE_POSITION_INDEPENDENT_CODE=TRUE ../.. \
    && make -j \
    && make install

RUN apt install intel-mkl-full libssl-dev libspdlog-dev libgflags-dev libgtest-dev libc-ares-dev -y -q

RUN git clone --recurse-submodules -b v1.7.1 https://github.com/facebookresearch/faiss \
    && cd /faiss \
    && cmake -DCMAKE_INSTALL_PREFIX=/usr -DFAISS_ENABLE_PYTHON=OFF -DBUILD_SHARED_LIBS=ON -DCMAKE_BUILD_TYPE=Release -DFAISS_OPT_LEVEL=avx2 -B build . \
    && make -C build -j faiss \
    && make -C build install

RUN git clone -b v1.14 https://github.com/civetweb/civetweb \
    && cd /civetweb \
    && make build lib slib \
    && make install install-headers install-lib install-slib


ENV CPATH="/usr/local/cuda-11.3/targets/x86_64-linux/include:${CPATH}"

RUN git clone https://github.com/jplu/faiss-grpc-server.git \
    && cd /faiss-grpc-server \
    && make cppclient \
    && mkdir build \
    && cd build \
    && cmake .. \
    && make

FROM nvidia/cuda:11.3.1-runtime-ubuntu20.04

COPY --from=builder /faiss-grpc-server/build/bin/faiss_server /home/

COPY --from=builder /usr/lib/x86_64-linux-gnu/libfaiss.so /usr/lib/x86_64-linux-gnu/

COPY --from=builder /usr/lib/libgrpc* /usr/lib/

COPY --from=builder /usr/lib/libgpr* /usr/lib/

COPY --from=builder /usr/lib/libupb* /usr/lib/

COPY --from=builder /usr/lib/libaddress_sorting* /usr/lib/

COPY --from=builder /usr/lib/libabsl* /usr/lib/

COPY --from=builder /usr/local/lib/libcivetweb* /usr/lib/

COPY --from=builder /usr/local/bin/civetweb /usr/bin/

COPY --from=builder /usr/lib/x86_64-linux-gnu/libproto* /usr/lib/x86_64-linux-gnu/

RUN echo 'debconf debconf/frontend select Noninteractive' | debconf-set-selections \
    && apt update \
    && apt install htop intel-mkl libgflags2.2 libspdlog1 wget -y -q \
    && GRPC_HEALTH_PROBE_VERSION=v0.4.4 \
    && wget -qO/bin/grpc_health_probe https://github.com/grpc-ecosystem/grpc-health-probe/releases/download/${GRPC_HEALTH_PROBE_VERSION}/grpc_health_probe-linux-amd64 \
    && chmod +x /bin/grpc_health_probe

WORKDIR /home

ENTRYPOINT ["./faiss_server"]

CMD ["--help"]
