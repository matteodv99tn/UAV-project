from __future__ import annotations

import sys
import os

from os.path import dirname, join
from tensorflow.keras import Input
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense

filedir = os.path.dirname(__file__)
parentdir = os.path.normpath(os.path.join(filedir, ".."))
sys.path.insert(0, parentdir)

from utils.wrappers import time_execution
from config import MODEL_DIR
from data_preparation import \
        load_dataframe, \
        load_data, \
        normalize_data, \
        shuffle_data, \
        split_data

INPUT_SIZE_DEFAULT: int = 3
OUTPUT_SIZE_DEFAULT: int = 1


class FullyConnectedNN:

    in_size: int = INPUT_SIZE_DEFAULT
    out_size: int = OUTPUT_SIZE_DEFAULT
    layers: tuple[int] = None
    model: Sequential = None

    def __init__(self, *args, **kwargs):
        self.set_attributes(**kwargs)
        self.layers = tuple(args)
        self.compile_model()

    def set_attributes(self, **kwargs):
        for key, value in kwargs.items():
            if hasattr(self, key):
                setattr(self, key, value)

    def __str__(self) -> str:
        return f"FullyConnectNN(in_size={self.in_size}, " \
               f"out_size={self.out_size}, " \
               f"layers={self.layers})"

    def compile_model(self) -> FullyConnectedNN:
        custom_layers = [Dense(layer_size, activation="relu")
                         for layer_size in self.layers]
        self.model = Sequential(layers=[
            Input(shape=(self.in_size,)),
            *custom_layers,
            Dense(self.out_size, activation="linear")
            ])
        self.model.compile(optimizer="adam", loss="mse",
                           metrics=["accuracy"])
        return self

    @time_execution
    def fit(self, *args, **kwargs):
        return self.model.fit(*args, **kwargs)

    def save(self) -> FullyConnectedNN:
        os.makedirs(MODEL_DIR, exist_ok=True)
        entities = [self.in_size, *self.layers, self.out_size]
        filename = "_".join([str(e) for e in entities]) + ".keras"
        self.model.save(join(MODEL_DIR, filename))
        return self


if __name__ == "__main__":
    df = load_dataframe()
    x_data, y_data = load_data()
    x_data, y_data = normalize_data(x_data, y_data)
    x_data, y_data = shuffle_data(x_data, y_data)
    (x_train, y_train), (x_val, y_val) = split_data(x_data, y_data)

    test_models = [(32, 32),
                   (64, 64),
                   (128, 128),
                   (32, 32, 32),
                   (64, 64, 64)]

    for model_config in test_models:
        nn = FullyConnectedNN(*model_config)
        print("Training", nn)
        nn.fit(x_train, y_train,
               epochs=50, validation_data=(x_val, y_val),
               verbose=0)
        nn.save()
