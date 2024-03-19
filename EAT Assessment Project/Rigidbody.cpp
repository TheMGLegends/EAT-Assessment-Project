#include "Rigidbody.h"

#include "PhysicsManager.h"

Rigidbody::Rigidbody() :
	mass{ BASE_MASS },
	force{},
	acceleration{},
	velocity{},
	displacement{}
{
}

void Rigidbody::UpdateRigidbody(float dt)
{
	PhysicsManager::Instance()->UpdatePhysics(dt, mass, force, acceleration, velocity, displacement);
}
