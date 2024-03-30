#pragma once

#include "Collider.h"

class BoxCollider : public Collider
{
private:
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
};

