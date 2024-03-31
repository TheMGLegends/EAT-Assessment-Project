#pragma once

#include "Collider.h"

/// @brief Abstract (Interface) class to be inherited by any class that needs to handle collision events
class ICollision
{
public:
	/// @brief The function that will be called when a collision event occurs
	/// @param other : The collider that this object collided with
	virtual void OnCollisionEnter(Collider* other) = 0;
};