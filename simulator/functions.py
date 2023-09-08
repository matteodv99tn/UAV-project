import numpy as np

from autogen.lib.turret_force import turret_force
from autogen.lib.force_contact1 import force_contact1
from autogen.lib.force_contact2 import force_contact2
from autogen.lib.force_contact3 import force_contact3
from autogen.lib.force_contact4 import force_contact4
from autogen.lib.contact_force_dt1 import contact_force_dt1
from autogen.lib.contact_force_dt2 import contact_force_dt2
from autogen.lib.contact_force_dt3 import contact_force_dt3
from autogen.lib.contact_force_dt4 import contact_force_dt4
from autogen.lib.system_model import system_model


def contact_force_dt(x: np.ndarray) -> np.ndarray:
    force: np.ndarray = overall_force(x)
    dFdt1: np.ndarray = np.nan_to_num(contact_force_dt1(x, force), nan=0)
    dFdt2: np.ndarray = np.nan_to_num(contact_force_dt2(x, force), nan=0)
    dFdt3: np.ndarray = np.nan_to_num(contact_force_dt3(x, force), nan=0)
    dFdt4: np.ndarray = np.nan_to_num(contact_force_dt4(x, force), nan=0)
    return dFdt1 + dFdt2 + dFdt3 + dFdt4


def overall_force(x: np.ndarray) -> np.ndarray:
    Fa = turret_force(x)
    return Fa + contact_force(x)


def contact_force(x: np.ndarray) -> np.ndarray:
    F1 = np.nan_to_num(force_contact1(x), nan=0)
    F2 = np.nan_to_num(force_contact2(x), nan=0)
    F3 = np.nan_to_num(force_contact3(x), nan=0)
    F4 = np.nan_to_num(force_contact4(x), nan=0)
    return F1 + F2 + F3 + F4


def system_dynamics(x: np.ndarray, u: np.ndarray) -> np.ndarray:
    force = overall_force(x)
    return system_model(x, np.concatenate((force, u)))
