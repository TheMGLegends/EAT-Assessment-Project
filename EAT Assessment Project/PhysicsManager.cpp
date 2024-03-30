/*
#include "PhysicsManager.h"

#include "MemoryLeakDetector.h"

PhysicsManager* Singleton<PhysicsManager>::instance = nullptr;

PhysicsManager::PhysicsManager() :
	globalGravity{ BASE_GRAVITY },
	dragCoefficient{ 0.5f },
	airDensity{ 1.225f },
	area{ 5.0f }
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

void PhysicsManager::UpdatePhysics(Rigidbody& rb, float dt)
{
	// INFO: Calculate Drag Force
	Vector2 dragForce = CalculateDragForce(rb);

	Vector2 totalForce;
	//totalForce.X = rb.force.X - dragForce.X;
	totalForce.Y = rb.force.Y - dragForce.Y;

	// INFO: Re-order 'F = MA' to calculate acceleration 'A = F/M'
	rb.acceleration.X = totalForce.X / rb.mass;
	rb.acceleration.Y = (totalForce.Y / rb.mass) + globalGravity; // INFO: Gravity added since SDL works with negative y is up and vice versa

	// INFO: Calculate new velocity using 'V = AT' and add it onto existing velocity
	rb.velocity += rb.acceleration * dt;

	// INFO: Calculate displacement uisng 'D = VT' and add it onto existing displacement
	rb.displacement += rb.velocity * dt;
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

Vector2 PhysicsManager::CalculateDragForce(Rigidbody& rb) const
{
	// INFO: Calculate Drag Force using 'D = Cd * r * V^2/2 * A'
	// Cd = Drag Coeefficient, r = Air Density, V = Velocity, A = Reference Area
	float dragForceX = dragCoefficient * airDensity * (rb.velocity.Magnitude() / 2) * area;
	float dragForceY = dragCoefficient * airDensity * (rb.velocity.Magnitude() / 2) * area;

	return Vector2(dragForceX, dragForceY);
}
*/

