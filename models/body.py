from __future__ import annotations
from typing import TYPE_CHECKING
if TYPE_CHECKING:
    from . import Turret

import numpy as np


class Body():
    """ Body class """
    turrets: list[Turret] = []

    def __init__(self, parameters):
        turret_pos = parameters["turrets"]
        pass

