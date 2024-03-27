#include "Collider.h"

#include "MemoryLeakDetector.h"

Collider::Collider(std::function<void(Collider*)> Response)
{
	// INFO: Set Collider Type to None ready for it 
	// to be set during the construction of shapes
	colliderType = ColliderType::None;

	// INFO: Set the bound provided function to the Collision Response
	CollisionResponse = Response;
}
