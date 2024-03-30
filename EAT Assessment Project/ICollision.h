#pragma once

#include "Collider.h"

/// <summary>
/// Abstract (Interface) class to be inherited by any class that needs to handle collision events
/// </summary>
class ICollision
{
public:
	virtual void OnCollisionEnter(Collider* other) = 0;
};