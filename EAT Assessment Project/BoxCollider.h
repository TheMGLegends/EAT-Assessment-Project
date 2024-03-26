#pragma once

#include "Collider.h"

class BoxCollider : public Collider
{
private:
	float* x;
	float* y;
	int* width;
	int* height;

public:
	/// <summary>
	/// Constructor of Box Collider, takes in the memory addresses of
	/// x, y, width and height of the game object that the collider is 
	/// attached to
	/// </summary>
	/// <param name="x">: The x position of the rect</param>
	/// <param name="y">: The y position of the rect</param>
	/// <param name="width">: The width of the rect</param>
	/// <param name="height">: The height of the rect</param>
	BoxCollider(float &x, float &y, int &width, int &height);

	/// <summary>
	/// Getter for the box colliders' x position
	/// </summary>
	/// <returns>The x position of the box collider</returns>
	inline float GetX() { return *x; }

	/// <summary>
	/// Getter for the box colliders' y position
	/// </summary>
	/// <returns>The y position of the box collider</returns>
	inline float GetY() { return *y; }

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
};

