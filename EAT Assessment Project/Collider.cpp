#include "Collider.h"

Collider::Collider(std::function<void(Collider*)> Response, float& x, float& y)
{
	// INFO: Set Collider Type to None ready for it 
	// to be set during the construction of shapes
	colliderType = ColliderType::None;

	// INFO: Set the bound provided function to the Collision Response
	CollisionResponse = Response;

	// INFO: Set the X and Y pointers to point to the provided x and y memory addresses
	X = &x;
	Y = &y;
}
