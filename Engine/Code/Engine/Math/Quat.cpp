#include "Engine/Math/Quat.hpp"
#include <cmath>

Quat::Quat(XrQuaternionf const& xrQuat)
{
	x = xrQuat.x;
	y = xrQuat.y;
	z = xrQuat.z;
	w = xrQuat.w;
}

Quat Quat::operator*(const Quat& q) const
{
	return Quat(
		w * q.w - x * q.x - y * q.y - z * q.z,
		w * q.x + x * q.w + y * q.z - z * q.y,
		w * q.y - x * q.z + y * q.w + z * q.x,
		w * q.z + x * q.y - y * q.x + z * q.w
	);
}

Quat Quat::Inverse() const
{
	return Quat(-x, -y, -z, w);
}

Quat Quat::CreateQuatByAngleAndAxis(float angle, Vec3 axis)
{
	float half_angle = angle * 0.5f;
	float s = sinf(half_angle);
	return Quat(axis.x * s, axis.y * s, axis.z * s, cos(half_angle));
}

Vec3 Quat::RotateVectorByQuat(Quat const& quat, Vec3 in_Vec)
{
	// Convert the vector into a pure quaternion
	Quat vecQuat(in_Vec.x, in_Vec.y, in_Vec.z, 0.f);

	// Perform the rotation: q * vec_q * q_inverse
	Quat quat_inv = quat.Inverse();
	Quat rotated_q = quat * vecQuat * quat_inv; // ???

	// Extract the rotated vector from the quat
	return Vec3(rotated_q.x,
				rotated_q.y,
				rotated_q.z);
}
