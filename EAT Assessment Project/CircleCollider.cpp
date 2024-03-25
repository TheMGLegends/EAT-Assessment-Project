#include "CircleCollider.h"

#include "CollisionManager.h"

CircleCollider::CircleCollider(float &x, float &y, int &radius)
{
	centreX = &x;
	centreY = &y;
	this->radius = &radius;

	// INFO: Adds the Collider to the Collision Manager
	CollisionManager::Instance()->AddColliderToVector(this);
}
