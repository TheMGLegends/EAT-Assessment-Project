#pragma once

#include "Collider.h"
#include "CircleCollider.h"
#include "BoxCollider.h"

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

	/// <summary>
	/// Checks the collisions between all colliders stored in the Collision Manager
	/// </summary>
	void CheckCollisions();

	/// <summary>
	/// Used for adding a collider to the colliders list in collision manager
	/// </summary>
	/// <param name="c">: The reference of the collider to be added to the list</param>
	void AddColliderToVector(Collider* c);

private:
	CollisionManager() {}
	~CollisionManager() {}

	static CollisionManager* instance;

	void CircleCircleCollision(CircleCollider* c1, CircleCollider* c2);
	void RectRectCollision(BoxCollider* b1, BoxCollider* b2);
	void CircleRectCollision(CircleCollider* c, BoxCollider* b);
};

