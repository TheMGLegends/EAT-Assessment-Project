#pragma once

#include "Vector2.h"

const float BASE_MASS = 1.0f;

enum class ForceMode
{
	Force,
	Acceleration,
	Impulse,
	VelocityChange
};

class Rigidbody
{
private:
	float mass;
	
	Vector2 force;
	Vector2 acceleration;
	Vector2 velocity;
	Vector2 displacement;
	
public:
	Rigidbody();

	/// <summary>
	/// Updates the values held in the rigidbody by passing them to the physics managers'
	/// update physics method
	/// </summary>
	void UpdateRigidbody(float dt);
};

