FROM ubuntu:latest

RUN apt-get update && apt-get install -y \
    xorg-dev \
    libx11-dev \
    libxext-dev \
    gcc \
    make

WORKDIR /minilibx

COPY . /minilibx

RUN make