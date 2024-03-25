#pragma once

#include "Collider.h"

#include <vector>

class CollisionManager
{
private:
	std::vector<Collider*> colliders;

public:
	// INFO: Delete the Copy Constructor and Assignment Operator for, so that 
	// you can't accidentally create more than one instance of the class

	CollisionManager(const CollisionManager&) = delete;
	void operator=(const CollisionManager&) = delete;

	/// <summary>
	/// Allows access to the singleton by returning it or creating one if one doesn't
	/// yet exist
	/// </summary>
	/// <returns>Returns a pointer to the instance of the class </returns>
	inline static CollisionManager* Instance() { return instance != nullptr ? instance : instance = new CollisionManager(); }

	/// <summary>
	/// Clean up method during program termination
	/// </summary>
	void Clean();

	void CheckCollisions();

private:
	CollisionManager() {}
	~CollisionManager() {}

	static CollisionManager* instance;
};

