#include "BoxCollider.h"

#include "CollisionManager.h"

BoxCollider::BoxCollider(std::function<void(Collider*)> Response, float &x, float &y, int &width, int &height) :
	Collider(Response, x, y)
{
	// INFO: Set the width and height pointers to point to the provided 
	// width and height memory addresses
	this->width = &width;
	this->height = &height;

	// INFO: Adds the Collider to the Collision Manager
	CollisionManager::Instance()->AddColliderToVector(this);
}
