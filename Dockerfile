ARG IMAGE=debian:13
ARG NETWORK_NM=OFF
ARG NETWORK_CM=OFF
FROM ${IMAGE} AS build
ARG IMAGE
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
        libxml2-dev \
        libidn2-0-dev
COPY . /lms/
RUN set -x && \
    cd /lms && \
    if [ "${IMAGE}" = "ubuntu:26.04" ]; then sed -i -E 's,libxml2,libxml2-16,g' CMakeLists.txt; fi && \
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

FROM ${IMAGE} AS test
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

FROM scratch AS artifacts
COPY --from=test /test/*.deb /
