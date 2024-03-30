#include "Collider.h"

#include "MemoryLeakDetector.h"

Collider::Collider(std::function<void(Collider*)> Response, float& x, float& y)
{
	// INFO: Set Collider Type to None ready for it 
	// to be set during the construction of shapes
	colliderType = ColliderType::None;

	// INFO: Set the bound provided function to the Collision Response
	CollisionResponse = Response;

	X = &x;
	Y = &y;
}
