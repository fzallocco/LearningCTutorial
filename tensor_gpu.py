import tensorflow as tf

tf.debugging.set_log_device_placement(True)
gpus = tf.config.list_physical_devices('GPU')
if gpus:
    print("TensorFlow found the following GPUs:")
    for gpu in gpus:
        print(gpu.name)
        print("  Memory:", tf.config.experimental.get_memory_info(gpu.name))
else:
    print("No GPUs found")