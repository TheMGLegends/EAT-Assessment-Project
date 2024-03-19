#pragma once

#include "Vector2.h"

const float BASE_MASS = 1.0f;

class Rigidbody
{
public:
	float mass;
	
	Vector2 force;
	Vector2 acceleration;
	Vector2 velocity;
	Vector2 displacement;
	
public:
	Rigidbody();
};

