#pragma once

#include "Engine/math/Vec3.hpp"

class Quat 
{
public:
	float x, y, z, w;

	Quat(float w = 1, float x = 0, float y = 0, float z = 0)
		: w(w), x(x), y(y), z(z) {}
	explicit Quat(XrQuaternionf const& xrQuat);

	// Quaternion multiplication
	Quat operator*(const Quat& q) const;

	// Quaternion inversion
	Quat Inverse() const;

	// Creating a quaternion from angle and axis
	static Quat CreateQuatByAngleAndAxis(float angle, Vec3 axis);
	static Vec3 RotateVectorByQuat(Quat const& quat, Vec3 in_Vec);
};