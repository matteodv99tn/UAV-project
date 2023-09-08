from __future__ import annotations

from tensorflow.keras import Input
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense

from utils.wrappers import time_execution
from os.path import join


class FullyConnectedNN:

    in_size: int = None
    out_size: int = None
    layers: tuple[int] = None
    model: Sequential = None

    def __init__(self, in_size, out_size, *args, **kwargs):
        self.in_size = in_size
        self.out_size = out_size
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

    def save(self, destination) -> FullyConnectedNN:
        entities = [self.in_size, *self.layers, self.out_size]
        filename = "_".join([str(e) for e in entities]) + ".keras"
        self.model.save(join(destination, filename))
        return self
