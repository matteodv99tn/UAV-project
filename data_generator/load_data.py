import pandas as pd


df = pd.read_pickle("data.pkl")

print(df.head())
print(type(df.loc[0, "states"]))
