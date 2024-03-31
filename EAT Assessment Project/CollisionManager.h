#pragma once

#include "Collider.h"
#include "CircleCollider.h"
#include "BoxCollider.h"

#include <vector>

/// @brief Defines the class responsible for managing the collisions between all colliders
class CollisionManager
{
private:
	std::vector<Collider*> colliders;

public:
	// INFO: Delete the Copy Constructor and Assignment Operator, so that 
	// you can't accidentally create more than one instance of the class

	CollisionManager(const CollisionManager&) = delete;
	void operator=(const CollisionManager&) = delete;

	/// @brief Allows access to the singleton by returning it or creating one if one doesn't yet exist
	/// @return A pointer to the instance of the class
	inline static CollisionManager* Instance() { return instance != nullptr ? instance : instance = new CollisionManager(); }

	/// @brief Clean up method during program termination
	void Clean();
	
	/// @brief Checks the collisions between all colliders stored in the Collision Manager
	void CheckCollisions();

	/// @brief Used for adding a collider to the colliders list in collision manager
	/// @param c : The collider to be added
	void AddColliderToVector(Collider* c);

private:
	CollisionManager() {}
	~CollisionManager() {}

	static CollisionManager* instance;

	/// @brief Collision Detection Algorithm between two circle colliders
	/// @param c1 : The first circle collider
	/// @param c2 : The second circle collider
	void CircleCircleCollision(CircleCollider* c1, CircleCollider* c2);

	/// @brief Collision Detection Algorithm between two box colliders
	/// @param b1 : The first box collider
	/// @param b2 : The second box collider
	void RectRectCollision(BoxCollider* b1, BoxCollider* b2);

	/// @brief Collision Detection Algorithm between a circle and a box collider
	/// @param c : The circle collider
	/// @param b : The box collider
	void CircleRectCollision(CircleCollider* c, BoxCollider* b);
};

