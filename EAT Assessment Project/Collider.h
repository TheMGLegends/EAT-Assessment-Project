#pragma once

#include <functional>

/// @brief An enum class to define the different types of colliders
enum class ColliderType
{
	None,

	Rect,
	Circle
};

/// @brief Defines the base class for all colliders
class Collider
{
protected:
	float* X;
	float* Y;

	ColliderType colliderType;

public:
	/// @brief Holds a bound function that is called when a collision occurs
	std::function<void(Collider*)> CollisionResponse;

public:
	/// @brief Constructor for the Collider class
	/// @param Response : The function to be bounded as the collision response
	/// @param x : The memory address that holds the x position of the object
	/// @param y : he memory address that holds the y position of the object
	Collider(std::function<void(Collider*)> Response, float &x, float &y);
	virtual ~Collider() {}

	/// @brief Getter for the Colliders' Type
	/// @return The type of collider that is on the object
	ColliderType GetColliderType() const { return colliderType; }

	/// @brief Setter for the Colliders' Type
	/// @param type : The type of collider
	void SetColliderType(ColliderType type) { colliderType = type; }

	/// @brief Getter for the colliders' x position
	/// @return The x position of the collider
	inline float GetX() { return *X; }

	/// @brief Getter for the colliders' y position
	/// @return The y position of the collider
	inline float GetY() { return *Y; }

	/// @brief Getter for the centre x position of the collider
	/// @return The centre x position of the collider
	virtual float GetCentreX() = 0;

	/// @brief Getter for the centre y position of the collider
	/// @return The centre y position of the collider
	virtual float GetCentreY() = 0;
};

