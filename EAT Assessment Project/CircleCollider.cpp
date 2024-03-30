#include "CircleCollider.h"

#include "CollisionManager.h"

CircleCollider::CircleCollider(std::function<void(Collider*)> Response, float &x, float &y, int &radius) :
	Collider(Response, x, y)
{
	// INFO: Set the radius pointer to point to the provided radius memory address
	this->radius = &radius;

	// INFO: Adds the Collider to the Collision Manager
	CollisionManager::Instance()->AddColliderToVector(this);
}
