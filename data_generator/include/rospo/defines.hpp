#ifndef ROSPO_DEFINES_HPP__
#define ROSPO_DEFINES_HPP__

#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>

typedef float float_t;
typedef Eigen::Matrix<float_t, Eigen::Dynamic, Eigen::Dynamic> Matrix_t;
typedef Eigen::Vector<float_t, Eigen::Dynamic> Vector_t;
typedef Eigen::Matrix<float_t, 3, 3> Matrix3_t;
typedef Eigen::Vector<float_t, 3> Vector3_t;
typedef Eigen::Matrix<float_t, 2, 2> Matrix2_t;
typedef Eigen::Vector<float_t, 2> Vector2_t;
typedef Eigen::Matrix<float_t, 3, 2> Matrix32_t;

#endif // ROSPO_DEFINES_HPP__
