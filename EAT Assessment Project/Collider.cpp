#include "Collider.h"

#include "MemoryLeakDetector.h"

Collider::Collider()
{
	// INFO: Set Collider Type to None ready for it 
	// to be set during the construction of shapes
	colliderType = ColliderType::None;
}
