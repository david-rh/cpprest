FROM registry.fedoraproject.org/fedora:35

LABEL maintainer="David Anderson"

RUN dnf install gcc-c++ asio-devel catch-devel openssl-devel git cmake -y

RUN git clone https://github.com/corvusoft/restbed.git && \
    mkdir restbed/build && cd restbed/build && \
    cmake -DBUILD_SSL=NO .. && make install

COPY hellorest.cpp .

RUN g++ hellorest.cpp -o hellocpp -I restbed/distribution/include -L restbed/distribution/library -lrestbed -Wl,-rpath=restbed/distribution/library

EXPOSE 9080

ENTRYPOINT ["./hellocpp"]

