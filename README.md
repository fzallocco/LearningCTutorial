# Welcome to My C Programming Tutorial

## Covering the Basics

I am covering the basics of C building on my knowledge of Java and Cstar.
More updates to follow.

### Requirements

To run the programs featured in this repository, you'll need the gcc compiler version 13, which you can install on your platform via distributors like MinGW

### Recommended
Alternatively, you can run a Docker container in interactive mode, using Linux commands to edit and compile C/C++ code independently of your Operating System.

Create NVIDIA SMI Docker image: `docker build -t cuda-nvidia-smi:dev . --no-cache`

Run container in interactive mode if gpu is available: `docker run --gpus all -it cuda-nvidia-smi:dev`

Run Container in interactive mode if no dedicated gpu is available: `docker run -it cuda-nvidia-smi:dev`

To compile C code in Linux: `gcc <Filename.c> -o Filename`

To compile C++ code in Linux: `g++ <Filename.c> -o Filename`

To compile CUDA code in Linux: `nvcc -o Filename <Filename.c>`

To run any of those programs: `./Filename`

Run this command to verify you have an Nvidia GPU device: `nvidia-smi`

Run this command to display Intel GPU device info: `intel_gpu_top`

Run this command to display Integrated Graphics info: `lshw -c display`

Run this command if you want to check out your cpu info: `top`

To exit interactive container: `exit`