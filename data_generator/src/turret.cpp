#include <rospo/turret.hpp>

#include <math.h>

#include <rospo/defines.hpp>
#include <rospo/parameters.hpp>


Vector3_t turret_dynamics(
        const Vector3_t& x,
        const Vector2_t& u){
    Vector3_t xdot;

    const float Omega = x(0);
    const float ii = x(1);
    const float v = u(0);
    const float num1 = MOTOR_K_TAU*pow(Omega, 2) - ii;
    const float den1 = MOTOR_J * MOTOR_KV;
    const float num2 = MOTOR_R*MOTOR_KV*ii - v*MOTOR_KV + Omega;
    const float den2 = MOTOR_L * MOTOR_KV;

    const float_t dx_1 = -num1/den1;
    const float_t dx_2 = -num2/den2;
    const float_t dx_3 = u(1);

    xdot << dx_1, dx_2, dx_3;
    return xdot;
}


Matrix3_t turret_jacobian_x(
        const Vector3_t& x,
        const Vector3_t& u) {

    Matrix3_t jac;

    const float_t Omega = x(0);

    const float_t jac_1_1 = -2*MOTOR_K_TAU*Omega/MOTOR_J;
    const float_t jac_1_2 = -1 / (MOTOR_J*MOTOR_KV);
    const float_t jac_2_1 = 1 / (MOTOR_L*MOTOR_KV);
    const float_t jac_2_2 = -MOTOR_R / MOTOR_L;

    jac << jac_1_1, jac_1_2, 0,
           jac_2_1, jac_2_2, 0,
           0,       0,       0;
    return jac;
}


Matrix32_t turret_jacobian_u(
        const Vector3_t& x,
        const Vector3_t& u) {

    Matrix32_t jac;
    jac << 0,         0,
           1/MOTOR_L, 0,
           0,         1;
    return jac;
}
