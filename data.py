import math
import numpy

# Data generated by maple
R = 0.7e0
L = 0.272e-2
kv = 25 * math.pi
J = 0.28e-3
v__ref = 0.148e2
i__ref = 14
P__ref = 155
load__ref = 1005
g = 0.981e1
Omega__ref = 0.3926990817e3
k__tau = 0.1155894994e-5
k__l = 0.6393155938e-4
i__min = -10
i__max = 30
m__body = 6
J__body = 0.61e0
pos__x__turr = 0.35e0
pos__y__turr = 0.2e0
pos__x__contact = 0.4e0
pos__y__contact = 0.25e0
gamma__4 = -0.4414500000e0
gamma__5 = 1
N_turr = 4
phi__min = -0.4710e1
phi__max = 0.4710e1
delta__max = 3
dF__max = 5
dt_controller = 0.1e1 / 0.100e3
Uvc_max = 25
TUvc_max = 3
rho__x = 1
rho__y = 0.6e0
c__1 = 0.4e0
c__2 = 0.8e0
kp__P = 5.2
kd__P = 4
kp__psi = 1.2
kd__psi = 1.4
gamma_P = 0.25e1
N_turr = 4
N_con = 4
F_turr_max = 0.9859049999e1
F_contact_max = 0.4414500000e0
N_states = 18
N_inputs = 8
P_turret1 = numpy.mat([pos__x__turr,pos__y__turr,1])
P_turret2 = numpy.mat([pos__x__turr,-pos__y__turr,1])
P_turret3 = numpy.mat([-pos__x__turr,pos__y__turr,1])
P_turret4 = numpy.mat([-pos__x__turr,-pos__y__turr,1])
P_contact1 = numpy.mat([pos__x__contact,pos__y__contact,1])
P_contact2 = numpy.mat([pos__x__contact,-pos__y__contact,1])
P_contact3 = numpy.mat([-pos__x__contact,pos__y__contact,1])
P_contact4 = numpy.mat([-pos__x__contact,-pos__y__contact,1])
