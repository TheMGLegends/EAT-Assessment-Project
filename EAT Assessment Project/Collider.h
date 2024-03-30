#pragma once

#include <functional>

enum class ColliderType
{
	None,

	Rect,
	Circle
};

/// <summary>
/// Defines the base class for all colliders
/// </summary>
class Collider
{
protected:
	float* X;
	float* Y;

	ColliderType colliderType;

public:
	/// <summary>
	/// Holds a bound function that is called when a collision occurs
	/// </summary>
	std::function<void(Collider*)> CollisionResponse;

public:
	/// <summary>
	/// Constructor of collider, takes in the memory addresses of x and y 
	/// values of the game object that the collider is attached to as well as
	/// the response function that is called when a collision occurs
	/// </summary>
	/// <param name="Response">: The function to be bounded as the collision response</param>
	/// <param name="x">: The x-coordinate of the object</param>
	/// <param name="y">: The y-coordinate of the object</param>
	Collider(std::function<void(Collider*)> Response, float &x, float &y);
	virtual ~Collider() {}

	/// <summary>
	/// Getter for the Colliders' Type
	/// </summary>
	/// <returns>The type of collider that is on the object</returns>
	ColliderType GetColliderType() const { return colliderType; }

	/// <summary>
	/// Setter for the Colliders' Type
	/// </summary>
	/// <param name="type">: The type of collider</param>
	void SetColliderType(ColliderType type) { colliderType = type; }

	/// <summary>
	/// Getter for the colliders' x position
	/// </summary>
	/// <returns>The x position of the collider</returns>
	inline float GetX() { return *X; }

	/// <summary>
	/// Getter for the colliders' y position
	/// </summary>
	/// <returns>The y position of the collider</returns>
	inline float GetY() { return *Y; }

	/// <summary>
	/// Getter for the centre x position of the collider
	/// </summary>
	/// <returns>The centre x position of the collider</returns>
	virtual float GetCentreX() = 0;

	/// <summary>
	/// Getter for the centre y position of the collider
	/// </summary>
	/// <returns>The centre y position of the collider</returns>
	virtual float GetCentreY() = 0;
};

