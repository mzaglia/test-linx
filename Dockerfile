FROM ubuntu:20.04


RUN apt-get update &&  DEBIAN_FRONTEND=noninteractiv  apt-get install --no-install-recommends -y g++ make cmake git libreadline-dev libboost-dev git
RUN  apt-get clean && \
  rm -rf /var/lib/apt

COPY . /test-linx
WORKDIR /test-linx

RUN git submodule update --init

RUN mkdir build && cmake -B build && cd build  && make -j4

CMD ["./build/processador"]
