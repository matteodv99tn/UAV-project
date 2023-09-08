from __future__ import annotations

from neuralnetworks import FullyConnectedNN
from config import MODEL_DIR
from data_preparation import \
        load_dataframe, \
        load_data, \
        normalize_data, \
        shuffle_data, \
        split_data
from data import N_turr


if __name__ == "__main__":
    print("loading dataframe")
    df = load_dataframe()
    print("preparing data")
    x_data, y_data = load_data()
    print("normalizing data")
    x_data, y_data = normalize_data(x_data, y_data)
    print("shuffling data")
    x_data, y_data = shuffle_data(x_data, y_data)
    print("splitting data")
    (x_train, y_train), (x_val, y_val) = split_data(x_data, y_data)

    test_models = [(32, 32),
                   (64, 64),
                   (128, 128),
                   (32, 32, 32),
                   (64, 64, 64),
                   (128, 128, 128)]

    for model_config in test_models:
        nn = FullyConnectedNN(2*N_turr + 3, 2*N_turr, *model_config)
        print("Training", nn)
        nn.fit(x_train, y_train,
               epochs=100, validation_data=(x_val, y_val),
               verbose=1)
        nn.save(MODEL_DIR)
        print(f"Trained in {nn.execution_time} seconds")
