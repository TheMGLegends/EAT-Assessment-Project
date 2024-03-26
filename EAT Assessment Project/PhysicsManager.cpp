#include "PhysicsManager.h"

#include "MemoryLeakDetector.h"

PhysicsManager* Singleton<PhysicsManager>::instance = nullptr;

PhysicsManager::PhysicsManager() :
	globalGravity{ BASE_GRAVITY }
{
}

void PhysicsManager::Clean()
{
	// INFO: Clean up the instance
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}

void PhysicsManager::UpdatePhysics(Rigidbody& rb, float dt) const
{
	// INFO: Re-order 'F = MA' to calculate acceleration 'A = F/M'
	rb.acceleration.X = rb.force.X / rb.mass;
	rb.acceleration.Y = (rb.force.Y / rb.mass) + globalGravity; // INFO: Gravity added since SDL works with negative y is up and vice versa

	// INFO: Calculate new velocity using 'V = AT'
	rb.velocity = rb.acceleration * dt;

	// INFO: Calculate displacement uisng 'D = VT'
	rb.displacement = rb.velocity * dt;
}

void PhysicsManager::AddForce(Rigidbody& rb, Vector2 force, float dt, ForceMode mode)
{
	switch (mode)
	{
	case ForceMode::Force:
		rb.force = (rb.force * dt) / rb.mass;
		break;
	case ForceMode::Acceleration:
		rb.force = rb.force * dt;
		break;
	case ForceMode::Impulse:
		rb.force = rb.force / rb.mass;
		break;
	case ForceMode::VelocityChange:
		rb.force = rb.force;
		break;
	default:
		break;
	}
}

