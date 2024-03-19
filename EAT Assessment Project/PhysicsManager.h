#pragma once

#include "Singleton.h"

#include "Vector2.h"

const float BASE_GRAVITY = 9.8f;

class PhysicsManager : public Singleton<PhysicsManager>
{
	// INFO: Grants the base class access to the private and protected
	// member variables and methods of the derived class, specifically
	// the constructor
	friend class Singleton<PhysicsManager>;

private:
	float globalGravity;

public:
	/// <summary>
	/// Clean up method during program termination
	/// </summary>
	void Clean() override;

	/// <summary>
	/// Used to update the values held in the rigidbody by having references
	/// to them so that the original values are changed rather than working
	/// with copies
	/// </summary>
	/// <param name="dt">: Delta Time</param>
	/// <param name="mass">: A reference to the mass of the rb</param>
	/// <param name="force">: A reference to the force of the rb</param>
	/// <param name="acceleration">: A reference to the acceleration of the rb</param>
	/// <param name="velocity">: A reference to the velocity of the rb</param>
	/// <param name="displacement">: A reference to the displacement of the rb</param>
	void UpdatePhysics(float dt, float& mass, Vector2& force, Vector2& acceleration,
					   Vector2& velocity, Vector2& displacement);

	/// <summary>
	/// The setter for global gravity
	/// </summary>
	/// <param name="gravity">: The new gravity to affect rigidbodies</param>
	inline void SetGravity(float gravity) { globalGravity = gravity; }

	/// <summary>
	/// The getter for global gravity
	/// </summary>
	/// <returns>The global gravity that affects all rigidbodies</returns>
	inline float GetGravity() const { return globalGravity; }

private:
	PhysicsManager();
};

