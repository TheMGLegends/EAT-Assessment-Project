#include "PhysicsManager.h"

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

void PhysicsManager::UpdatePhysics(float dt, float& mass, Vector2& force, Vector2& acceleration, 
								   Vector2& velocity, Vector2& displacement)
{
	// INFO: Re-order 'F = MA' to calculate acceleration 'A = F/M'
	acceleration.X = force.X / mass;
	acceleration.Y = (force.Y / mass) + globalGravity; // INFO: Gravity added since SDL works with negative y is up and vice versa

	// INFO: Calculate new velocity using 'V = AT'
	velocity = acceleration * dt;

	// INFO: Calculate displacement uisng 'D = VT'
	displacement = velocity * dt;
}

