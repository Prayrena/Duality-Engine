#pragma once

#include "Engine/Animation/Skeleton.hpp"
#include "Engine/Math/Mat44.hpp"

struct FTwoBoneSolver
{
	// change all to Joint?
	Joint* m_root; // shoulder
	Joint* m_mid;  // elbow
	Joint* m_end;  // hand

	Mat44 Root; // shoulder
	Mat44 Mid;  // elbow
	Mat44 End;  // hand

	void Solve(const Vec3& Target); // updates transforms in-place
};