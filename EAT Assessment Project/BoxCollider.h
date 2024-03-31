#pragma once

#include "Collider.h"

/// @brief Defines the box collider class to be used by rect shaped objects
class BoxCollider : public Collider
{
private:
	int* width;
	int* height;

public:	
	/// @brief Constructor of Box Collider
	/// @param Response : The function to be bounded as the collision response
	/// @param x : The memory address that holds the x position of the rect
	/// @param y : The memory address that holds the y position of the rect
	/// @param width : The memory address that holds the width of the rect
	/// @param height : The memory address that holds the height of the rect
	BoxCollider(std::function<void(Collider*)> Response, float &x, float &y, int &width, int &height);

	/// @brief Getter for the box colliders' width
	/// @return The width of the box collider
	inline int GetWidth() { return *width; }

	/// @brief Getter for the box colliders' height
	/// @return The height of the box collider
	inline int GetHeight() { return *height; }

	/// @brief Getter for the box colliders' centre x
	/// @return The centre x of the box collider
	inline float GetCentreX() override { return *X + *width / 2.0f; }

	/// @brief Getter for the box colliders' centre y
	/// @return The centre y of the box collider
	inline float GetCentreY() override { return *Y + *height / 2.0f; }
};

