#pragma once

#include "Collider.h"
#include "CircleCollider.h"
#include "BoxCollider.h"

#include <vector>

/// <summary>
/// Defines the class responsible for managing the collisions between all colliders
/// </summary>
class CollisionManager
{
private:
	std::vector<Collider*> colliders;

public:
	// INFO: Delete the Copy Constructor and Assignment Operator, so that 
	// you can't accidentally create more than one instance of the class

	CollisionManager(const CollisionManager&) = delete;
	void operator=(const CollisionManager&) = delete;

	/// <summary>
	/// Allows access to the singleton by returning it or creating one if one doesn't
	/// yet exist
	/// </summary>
	/// <returns>A pointer to the instance of the class </returns>
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

	/// <summary>
	/// Collision Detection Algorithm between two circle colliders
	/// </summary>
	/// <param name="c1">: The first circle collider</param>
	/// <param name="c2">: The second circle collider</param>
	void CircleCircleCollision(CircleCollider* c1, CircleCollider* c2);

	/// <summary>
	/// Collision Detection Algorithm between two box colliders
	/// </summary>
	/// <param name="b1">: The first box collider</param>
	/// <param name="b2">: The second box collider</param>
	void RectRectCollision(BoxCollider* b1, BoxCollider* b2);

	/// <summary>
	/// Collision Detection Algorithm between a circle and a box collider
	/// </summary>
	/// <param name="c">: The circle collider</param>
	/// <param name="b">: The box collider</param>
	void CircleRectCollision(CircleCollider* c, BoxCollider* b);
};

