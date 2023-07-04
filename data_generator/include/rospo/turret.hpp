#ifndef ROSPO_TURRET_HPP__
#define ROSPO_TURRET_HPP__

#include <rospo/defines.hpp>


Vector3_t turret_dynamics(
        const Vector3_t& x,
        const Vector3_t& u);


Matrix3_t turret_jacobian_x(
        const Vector3_t& x,
        const Vector3_t& u);


Matrix32_t turret_jacobian_u(
        const Vector3_t& x,
        const Vector3_t& u);


#endif // ROSPO_TURRET_HPP__
