import tensorflow as tf

gpus = tf.config.list_physical_devices('GPU')
if gpus:
    print("TensorFlow found the following GPUs:")
    for gpu in gpus:
        print(gpu.name)
else:
    print("No GPUs found")