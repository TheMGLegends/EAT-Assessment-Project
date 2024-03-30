#pragma once

#include "Collider.h"

/// <summary>
/// Defines the box collider class to be used by rect shaped objects
/// </summary>
class BoxCollider : public Collider
{
private:
	int* width;
	int* height;

public:
	/// <summary>
	/// Constructor of Box Collider, takes in the memory addresses of
	/// x, y, width and height of the game object that the collider is 
	/// attached to as well as the response function that is called when a
	/// collision occurs
	/// </summary>
	/// <param name="Response">: The function to be bounded as the collision response</param>
	/// <param name="x">: The x position of the rect</param>
	/// <param name="y">: The y position of the rect</param>
	/// <param name="width">: The width of the rect</param>
	/// <param name="height">: The height of the rect</param>
	BoxCollider(std::function<void(Collider*)> Response, float &x, float &y, int &width, int &height);

	/// <summary>
	/// Getter for the box colliders' width
	/// </summary>
	/// <returns>The width of the box collider</returns>
	inline int GetWidth() { return *width; }

	/// <summary>
	/// Getter for the box colliders' height
	/// </summary>
	/// <returns>The height of the box collider</returns>
	inline int GetHeight() { return *height; }

	/// <summary>
	/// Getter for the box colliders' centre x
	/// </summary>
	/// <returns>The centre x of the box collider</returns>
	inline float GetCentreX() override { return *X + *width / 2.0f; }

	/// <summary>
	/// Getter for the box colliders' centre y
	/// </summary>
	/// <returns>The centre y of the box collider</returns>
	inline float GetCentreY() override { return *Y + *height / 2.0f; }
};

