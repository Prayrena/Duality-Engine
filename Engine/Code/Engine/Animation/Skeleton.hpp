#pragma once
#include "Engine/Math/Quat.hpp"
#include <string>
#include <vector>
#include <map>

class Joint 
{
public:
	Joint(std::string const& name, float length = 1.0f, Joint* parent = nullptr, Quat relativeRotation = Quat());

	std::string			m_name;         // Name of the joint
	Joint*				m_parent;       // Pointer to the parent joint (nullptr if root)
	std::vector<Joint*> m_children;		// Child joints

	// Transformation data
	float	m_boneLength;				// Length of the bone connecting to this joint ??? is this needed
	Quat	m_localRotation;			// Local rotation relative to the parent

	Vec3	m_pos;						// World position of the joint


	// Update the world position based on parent's position and rotation
	void UpdatePosition();
};

class Skeleton {
public:

	Skeleton(const std::string& root_name, float root_length = 1.0f); // ??? what is root length? root to pelvis?
	~Skeleton(); // clean up all its allocated joints

	Joint* m_root;								// Root joint of the skeleton
	std::map<std::string, Joint*> m_allJoints;	// record all the joints

	// Recursive deletion of joints
	void DeleteJointRecursive(Joint* joint);

	// Add a joint to the skeleton
	Joint* AddJoint(const std::string& name, float length = 1.f, Joint* parent = nullptr, Quat relativeQuat = Quat());

	// Update the entire skeleton's joints
	void Update();
};