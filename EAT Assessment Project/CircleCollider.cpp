#include "CircleCollider.h"

#include "CollisionManager.h"

#include "MemoryLeakDetector.h"

CircleCollider::CircleCollider(float &x, float &y, int &radius)
{
	X = &x;
	Y = &y;
	this->radius = &radius;

	// INFO: Adds the Collider to the Collision Manager
	CollisionManager::Instance()->AddColliderToVector(this);
}
