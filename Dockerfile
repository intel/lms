ARG IMAGE=debian:12
ARG NETWORK_NM=OFF
ARG NETWORK_CM=OFF
FROM ${IMAGE} as build
ENV DEBIAN_FRONTEND=noninteractive TZ=Etc/UTC
RUN apt-get update && \
    apt-get install -y \
        cmake \
        file \
        g++ \
        git \
        python3 \
        devscripts \
        libace-dev \
        libglib2.0-dev \
        libcurl4-openssl-dev \
        libxerces-c-dev \
        libnl-3-dev \
        libnl-route-3-dev \
        libxml2-dev
COPY . /lms/
RUN set -x && \
    cd /lms && \
    mkdir build && \
    cd build && \
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DNETWORK_NM=${NETWORK_NM} \
        -DNETWORK_CM=${NETWORK_CM} \
        .. && \
    make -j$(nproc) package && \
    ldd UNS/lms && \
    dpkg-deb --info *.deb && \
    dpkg-deb --contents *.deb

FROM ${IMAGE} as test
ENV DEBIAN_FRONTEND=noninteractive TZ=Etc/UTC
RUN apt-get update && \
    apt-get install -y \
        dpkg-dev
COPY --from=build /lms/build/*.deb /test/
RUN cd /test && \
    dpkg-scanpackages . >Packages && \
    echo 'deb [trusted=yes] file:/test ./' >/etc/apt/sources.list.d/test.list && \
    apt-get update
RUN apt-get install -y lms

FROM scratch as artifacts
COPY --from=test /test/*.deb /
