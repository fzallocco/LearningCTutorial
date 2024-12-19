import GPUtil

def get_gpu_info():
    gpus = GPUtil.getGPUs()
    gpu_info = []

    for gpu in gpus:
        info = {
            "id": gpu.id,
            "name": gpu.name,
            "load": gpu.load,
            "memory_total": gpu.memoryTotal,
            "memory_used": gpu.memoryUsed,
            "memory_free": gpu.memoryFree,
            "temperature": gpu.temperature
        }
        gpu_info.append(info)

    return gpu_info

if __name__ == "__main__":
    gpu_info = get_gpu_info()
    for gpu in gpu_info:
        print(gpu)