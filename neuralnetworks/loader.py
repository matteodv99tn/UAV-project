import os
from . import FullyConnectedNN


def load_model(fullpath: str) -> FullyConnectedNN:
    from keras.models import load_model
    filename = os.path.basename(fullpath)
    entities = filename.split(".")[0].split("_")
    nn = FullyConnectedNN(*[int(e) for e in entities[1:-1]])
    nn.model = load_model(fullpath)
    return nn
