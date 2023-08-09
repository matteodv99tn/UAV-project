import yaml
from yaml.loader import SafeLoader


with open('parameters.yaml') as f:
    data = yaml.load(f, Loader=SafeLoader)
    print(data)
