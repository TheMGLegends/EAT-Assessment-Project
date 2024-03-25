#include "BoxCollider.h"

#include "CollisionManager.h"

BoxCollider::BoxCollider(float &x, float &y, int &width, int &height)
{
	this->x = &x;
	this->y = &y;
	this->width = &width;
	this->height = &height;

	// INFO: Adds the Collider to the Collision Manager
	CollisionManager::Instance()->AddColliderToVector(this);
}
