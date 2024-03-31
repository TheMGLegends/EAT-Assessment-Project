#pragma once

#include "Collider.h"

/// @brief Defines the circle collider class to be used by spherically shaped objects
class CircleCollider : public Collider
{
private:
	int* radius;

public:
	/// @brief Constructor for the circle collider
	/// @param Response : The function to be bounded as the collision response
	/// @param x : The memory address that holds the x-coordinate of the circle
	/// @param y : The memory address that holds the y-coordinate of the circle
	/// @param radius : The memory address that holds the radius of the circle
	CircleCollider(std::function<void(Collider*)> Response, float &x, float &y, int &radius);

	/// @brief Getter for the circle colliders' radius
	/// @return The radius of the circle collider
	inline int GetRadius() { return *radius; }

	/// @brief Getter for the circle colliders' centre x
	/// @return The centre x of the circle collider
	inline float GetCentreX() override { return *X + *radius; }

	/// @brief Getter for the circle colliders' centre y
	/// @return The centre y of the circle collider
	inline float GetCentreY() override { return *Y + *radius; }
};

