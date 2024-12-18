# Use a base image with build tools
FROM ubuntu:latest

# Install necessary packages
RUN apt-get update && apt-get install -y \
    nmap \
    vim \
    build-essential \
    gcc \
    g++ \
    make

# Set the working directory
WORKDIR /app

# Copy the Makefile and source code
COPY Makefile .
COPY *.c *.cpp *.cu .

# Build the project
#RUN make #uncomment this to run all the programs, but specify this in Makefile

# Specify the command to run when the container starts
#CMD ["./your_executable"] #uncomment this to run c/c++ executables