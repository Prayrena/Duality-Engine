#include "Engine/Animation/Skeleton.hpp"

Joint::Joint(std::string const& name, float length /*= 1.0f*/, Joint* parent /*= nullptr*/,  Quat relativeRotation /*= Quat()*/)
	: m_name(name)
	, m_parent(parent)
	, m_boneLength(length)
	, m_localRotation(relativeRotation)
{
	if (parent) 
	{
		parent->m_children.push_back(this);
	}
}

void Joint::UpdatePosition()
{
	// if (m_parent) 
	// {
	// 	// Assume the bone extends along the local X-axis for simplicity
	// 	// Apply parent's rotation to the local bone vector
	// 	float local_bone[3] = { m_boneLength, 0.0f, 0.0f };
	// 	float rotated_bone[3];
	// 	rotateVector(m_parent->m_localRotation, local_bone, rotated_bone);
	// 
	// 	// Update this joint's position
	// 	position[0] = m_parent->position[0] + rotated_bone[0];
	// 	position[1] = m_parent->position[1] + rotated_bone[1];
	// 	position[2] = m_parent->position[2] + rotated_bone[2];
	// }
	// else {
	// 	// Root joint's position remains as is
	// }
	// 
	// // Recursively update children's positions
	// for (Joint* child : m_children) {
	// 	child->updatePosition();
	// }
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
Skeleton::Skeleton(const std::string& root_name, float root_length /*= 1.0f*/)
{
	m_root = new Joint(root_name, root_length, nullptr);

	// Initialize root position ?
}

Skeleton::~Skeleton()
{
	DeleteJointRecursive(m_root);
}

void Skeleton::DeleteJointRecursive(Joint* joint)
{
	if (joint)
	{
		for (Joint* child : joint->m_children) {
			DeleteJointRecursive(child);
		}
		delete joint;
	}
}

Joint* Skeleton::AddJoint(const std::string& name, float length /*= 1.f*/, Joint* parent /*= nullptr*/, Quat relativeQuat /*= Quat()*/)
{

	Joint* newJoint = new Joint(name, length, parent, relativeQuat);
	m_allJoints[name] = newJoint;

	// if the joint's parent is not specified, it will be connected to the root
	if (!parent) 
	{
		m_root->m_children.push_back(newJoint);
	}

	// initialize new_joint's position based on parent's
	newJoint->UpdatePosition();
	return newJoint;
}

void Skeleton::Update()
{
	if (m_root) 
	{
		m_root->UpdatePosition();
	}
}
