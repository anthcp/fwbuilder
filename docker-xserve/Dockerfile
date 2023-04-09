FROM ubuntu:focal as builder

ARG APP_VERSION=dev
ARG CPUS=1

RUN apt-get update &&\
    echo 'tzdata tzdata/Areas select Australia' | debconf-set-selections &&\
    echo 'tzdata tzdata/Zones/Australia select Adelaide' | debconf-set-selections &&\
    DEBIAN_FRONTEND="noninteractive" apt-get install -y -o Acquire::Retries=3 cmake git automake autoconf libtool libxml2-dev libxslt-dev libsnmp-dev qt5-default qttools5-dev-tools checkinstall &&\
    rm -rf /var/lib/apt/lists/*
# RUN apt-get update && apt-get install -y git

RUN git clone https://github.com/anthcp/fwbuilder.git /fwbuilder

WORKDIR /fwbuilder
RUN git checkout dev && mkdir -p build

# RUN ./autogen.sh &&\
#     make CXXFLAGS="-Wno-error=format-truncation -fPIC"

RUN cd build && cmake .. && cmake --build . && cpack

# dirty solutions
# RUN checkinstall --install=no --maintainer="Rafael Chicoli" --pkgname=fwbuilder --pkgversion=v6.0.0-rc1 --backup=no --fstrans=no -y &&\
#     rm /fwbuilder/fwbuilder_v6.0.0-rc1_amd64.deb
# RUN checkinstall --install=no --maintainer="Rafael Chicoli" --pkgname=fwbuilder --pkgversion=v6.0.0-rc1 --backup=no --fstrans=yes --requires=libxml2,libxslt1.1,libsnmp30,libqt5printsupport5 -y


FROM ubuntu:focal

COPY --from=builder /fwbuilder/fwbuilder_6.0.0-beta-1_amd64.deb /

RUN apt-get update &&\
    apt-get install -y --no-install-recommends libxml2 libxslt1.1 libsnmp30 libqt5printsupport5 &&\
    rm -rf /var/lib/apt/lists/*

RUN dpkg -i /fwbuilder_6.0.0-beta-1_amd64.deb &&\
    rm /fwbuilder_6.0.0-beta-1_amd64.deb

RUN useradd -m -d /home/fwbuilder fwbuilder

USER fwbuilder
WORKDIR /home/fwbuilder
CMD ["/usr/local/bin/fwbuilder"]