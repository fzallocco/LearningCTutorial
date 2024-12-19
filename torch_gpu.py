import torch

if torch.cuda.is_available():
    print("CUDA is available")
    print("Number of GPUs:", torch.cuda.device_count())
    print("Current GPU:", torch.cuda.current_device())
    print("GPU name:", torch.cuda.get_device_name(0))
    print("Total memory:", torch.cuda.get_device_properties(0).total_memory)
else:
    print("CUDA is not available")