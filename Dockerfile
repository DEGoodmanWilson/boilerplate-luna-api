FROM degoodmanwilson/conan-luna

MAINTAINER D.E. Goodman-Wilson

WORKDIR /app
ADD . /app
RUN conan --version
RUN conan install -s compiler=gcc -s compiler.version=5.4 -s compiler.libcxx=libstdc++11 --build=missing
RUN cmake .
RUN cmake --build .
ENV PORT 4567
EXPOSE 4567
