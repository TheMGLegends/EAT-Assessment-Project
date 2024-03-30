#include "BoxCollider.h"

#include "CollisionManager.h"

#include "MemoryLeakDetector.h"

BoxCollider::BoxCollider(std::function<void(Collider*)> Response, float &x, float &y, int &width, int &height) :
	Collider(Response, x, y)
{
	this->width = &width;
	this->height = &height;

	// INFO: Adds the Collider to the Collision Manager
	CollisionManager::Instance()->AddColliderToVector(this);
}
