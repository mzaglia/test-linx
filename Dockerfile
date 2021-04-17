FROM ubuntu:20.04


RUN apt-get update &&  DEBIAN_FRONTEND=noninteractiv apt-get install --no-install-recommends -y g++ make cmake git libreadline-dev libboost-dev
RUN  apt-get clean && \
  rm -rf /var/lib/apt

COPY . ./test-linx
WORKDIR /test-linx

RUN git submodule update --init

RUN cmake -DCMAKE_INSTALL_PREFIX="." -DCMAKE_BUILD_TYPE=Release -B build && cd build  && make -j4 && make install

ENTRYPOINT ["/test-linx/bin/processador"]
