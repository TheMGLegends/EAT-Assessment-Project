#pragma once

#include "Singleton.h"

#include "Rigidbody.h"

const float BASE_GRAVITY = 9.8f;

enum class ForceMode
{
	Force,
	Acceleration,
	Impulse,
	VelocityChange
};

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
	/// <param name="rb">: Reference to the Rigidbody</param>
	/// <param name="dt">: Delta Time</param>
	void UpdatePhysics(Rigidbody& rb, float dt) const;

	/// <summary>
	/// Used to add forces to a rigidbody to change the movement of the GO that
	/// they are attached to
	/// </summary>
	/// <param name="rb">: Reference to the Rigidbody</param>
	/// <param name="force">: The force to be applied to the rigidbody</param>
	/// <param name="dt">: Delta Time</param>
	/// <param name="mode">: How the force should be applied to the rigidbody</param>
	void AddForce(Rigidbody& rb, Vector2 force, float dt, ForceMode mode = ForceMode::Force);

	/// <summary>
	/// Cancels the force currently affecting the rigidbody
	/// </summary>
	/// <param name="rb">: Reference to the Rigidbody</param>
	inline void CancelForce(Rigidbody& rb) { rb.force = Vector2::ZERO; }

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

