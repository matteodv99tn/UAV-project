import numpy as np
import pandas as pd
import os

from sklearn.preprocessing import MinMaxScaler

from config import x_lb, x_ub, u_lb, u_ub, F_lb, F_ub

x_data_scaler = MinMaxScaler()
y_data_scaler = MinMaxScaler()

x_data_scaler.fit(np.stack((np.concatenate((x_lb, F_lb)),
                            np.concatenate((x_ub, F_ub)))))
y_data_scaler.fit(np.stack((u_lb, u_ub)))


def load_dataframe(filename: str = None) -> pd.DataFrame:
    if filename is None:
        filename = os.path.join(os.path.dirname(__file__), "data.pkl")
    df = pd.read_pickle(filename)

    df["x_data"] = df.apply(
            lambda row: np.concatenate((row["state"], row["target"])),
            axis=1)
    df["y_data"] = df["input"]

    return df


def load_data(df: pd.DataFrame = None) -> tuple[np.ndarray, np.ndarray]:
    if df is None:
        df = load_dataframe()
    x_data = np.stack(df["x_data"].values, axis=0)
    y_data = np.stack(df["y_data"].values, axis=0)
    return x_data, y_data


def shuffle_data(x_data: np.ndarray,
                 y_data: np.ndarray) -> tuple[np.ndarray, np.ndarray]:
    indices = np.arange(x_data.shape[0])
    np.random.shuffle(indices)
    return x_data[indices], y_data[indices]


def split_data(x_data: np.ndarray,
               y_data: np.ndarray,
               validation_ratio: float = 0.2
               ) -> tuple[tuple[np.ndarray, np.ndarray]]:
    # data are not shuffled here!
    N = x_data.shape[0]
    Nval = int(N * validation_ratio)
    x_train, y_train = x_data[:-Nval], y_data[:-Nval]
    x_val, y_val = x_data[-Nval:], y_data[-Nval:]
    return (x_train, y_train), (x_val, y_val)


def normalize_x_data(x_data: np.ndarray) -> np.ndarray:
    return x_data_scaler.transform(x_data)


def normalize_y_data(y_data: np.ndarray) -> np.ndarray:
    return y_data_scaler.transform(y_data)


def denormalize_x_data(x_data: np.ndarray) -> np.ndarray:
    return x_data_scaler.inverse_transform(x_data)


def denormalize_y_data(y_data: np.ndarray) -> np.ndarray:
    return y_data_scaler.inverse_transform(y_data)


def normalize_data(x_data: np.ndarray,
                   y_data: np.ndarray) -> tuple[np.ndarray, np.ndarray]:
    return normalize_x_data(x_data), normalize_y_data(y_data)


def denormalize_data(x_data: np.ndarray,
                     y_data: np.ndarray) -> tuple[np.ndarray, np.ndarray]:
    return denormalize_x_data(x_data), denormalize_y_data(y_data)
