#ifndef DEFINES_HPP__
#define DEFINES_HPP__

#include <eigen3/Eigen/Dense>

typedef double float_t;

typedef Eigen::Matrix<float_t, Eigen::Dynamic, Eigen::Dynamic> Matrix_t;
typedef Eigen::Vector<float_t, Eigen::Dynamic> Vector_t;
typedef Eigen::Vector<float_t, 1> Vector1_t;
typedef Eigen::Vector<float_t, 2> Vector2_t;
typedef Eigen::Vector<float_t, 3> Vector3_t;
typedef Eigen::Vector<float_t, 4> Vector4_t;

typedef Eigen::Matrix<float_t, 2, 2> Matrix2_t;
typedef Eigen::Matrix<float_t, 3, 3> Matrix3_t;
typedef Eigen::Matrix<float_t, 4, 4> Matrix4_t;


#endif // DEFINES_HPP__
