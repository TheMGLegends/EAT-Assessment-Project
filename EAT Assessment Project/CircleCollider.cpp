#include "CircleCollider.h"

#include "CollisionManager.h"

#include "MemoryLeakDetector.h"

CircleCollider::CircleCollider(std::function<void(Collider*)> Response, float &x, float &y, int &radius) :
	Collider(Response)
{
	X = &x;
	Y = &y;
	this->radius = &radius;

	// INFO: Adds the Collider to the Collision Manager
	CollisionManager::Instance()->AddColliderToVector(this);
}
