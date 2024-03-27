#pragma once

#include "Collider.h"

class ICollision
{
public:
	virtual void OnCollisionEnter(Collider* other) = 0;
};