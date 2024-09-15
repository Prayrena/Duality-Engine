#include "Engine/Animation/ProceduralAnimation/IKTwoBonesSolver.hpp"
#include "Engine/Math/MathUtils.hpp"
#include "Engine/core/VertexUtils.hpp"
#include "Engine/Math/MathUtils.hpp"
#include "Engine/core/EngineCommon.hpp"

void FTwoBoneSolver::Solve(const Vec3& Target)
{
	// // input pos
	// Vec3 InEndPos = End.GetTranslation3D();
	// Vec3 InMidPos = Mid.GetTranslation3D();
	// Vec3 InRootPos = Root.GetTranslation3D();
	// 
	// // Get length
	// float UpperLen = GetDistance3D(InRootPos, InMidPos);
	// float LowerLen = GetDistance3D(InMidPos, InEndPos);
	// // Max Length is the maximum offset we can take the hand from the shoulder
	// // we clamp 0.1f shorter to avoid edge cases
	// float MaxLength = UpperLen + LowerLen - 0.1f; 
	// 
	// // recognize that the three points lie on a flat plane
	// // decompose into two orthogonal “basis vectors”
	// Vec3 ToEnd = (InEndPos - InRootPos).GetNormalized();
	// Vec3 InPoleVec = FVector::VectorPlaneProject(InMidLoc - InRootLoc, ToEnd);
	// // InPoleVec.Normalize();
	// 
	UNUSED(Target);
	// UNUSED(MaxLength);
	// 
	// // a is the hip joint, b is the knee joint, c is the heel joint, and t is the target location
	// // The first step is to rotate the joints in the chain such that length of the vector from a to c 
	// // matches the length of the vector from a to t
	// float eps = 0.01f;
	// float lab = length(b - a);
	// float lcb = length(b - c);
	// float lat = clamp(length(t - a), eps, lab + lcb - eps);

	// Step 1: Extend/Contract the Joint Chain
	Joint*& A = m_root;
	Joint*& B = m_mid;
	Joint*& C = m_end;
	Vec3 T = Target;

	float eps = 0.01f;
	float l_AB = GetDistance3D(B->m_pos, A->m_pos);
	float l_CB = GetDistance3D(B->m_pos, C->m_pos);
	float l_AT = GetClamped(GetDistance3D(T, A->m_pos), eps, (l_AB + l_CB - eps));
}

