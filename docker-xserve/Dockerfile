FROM ubuntu:focal

ARG APP_VERSION=dev
ARG CPUS=1

RUN apt-get update &&\
    echo 'tzdata tzdata/Areas select Australia' | debconf-set-selections &&\
    echo 'tzdata tzdata/Zones/Australia select Adelaide' | debconf-set-selections &&\
    DEBIAN_FRONTEND="noninteractive" apt-get install -y -o Acquire::Retries=3 cmake git automake autoconf libtool libxml2-dev libxslt-dev libsnmp-dev qt5-default qttools5-dev-tools checkinstall &&\
    rm -rf /var/lib/apt/lists/*

RUN git clone https://github.com/anthcp/fwbuilder.git /fwbuilder

WORKDIR /fwbuilder
RUN git checkout master && mkdir -p build

RUN cd build && cmake .. && make && make install

RUN useradd -m -d /home/fwbuilder fwbuilder

USER fwbuilder
WORKDIR /home/fwbuilder
CMD ["/usr/local/bin/fwbuilder"]