# Use a base image with build tools
#FROM ubuntu:latest
FROM nvidia/cuda:12.2.0-devel-ubuntu22.04

# Set envrionment variables
ENV DEBIAN_FRONTEND=noninteractive

# Install necessary packages
RUN apt-get update && apt-get upgrade -y && apt-get install -y \
    python3 python3-pip \
    nmap \
    vim \
    build-essential \
    gcc \
    g++ \
    make \
    git \
    curl \
    intel-gpu-tools \
    lshw \
    nvidia-utils-525 \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

# Set the working directory
WORKDIR /app

# Copy the Makefile and source code
COPY Makefile .
COPY *.c *.cpp *.cu .
COPY requirements.txt .

# Build the project
#RUN make #uncomment this to run all the programs, but specify this in Makefile

RUN pip install --no-cache-dir -r requirements.txt
RUN gcc --version
RUN g++ --version
RUN nvcc --version
# Specify the command to run when the container starts
CMD ["bash"]