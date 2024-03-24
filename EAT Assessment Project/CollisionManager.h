#pragma once

#include "Singleton.h"

#include "Collider.h"

#include <vector>

class CollisionManager : public Singleton<CollisionManager>
{
	// INFO: Grants the base class access to the private and protected
	// member variables and methods of the derived class, specifically
	// the constructor
	friend class Singleton<CollisionManager>;

private:
	std::vector<Collider*> colliders;

public:
	/// <summary>
	/// Clean up method during program termination
	/// </summary>
	void Clean() override;

	void CheckCollisions();

private:
	CollisionManager();
};

