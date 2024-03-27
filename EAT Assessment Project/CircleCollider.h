#pragma once

#include "Collider.h"

class CircleCollider : public Collider
{
private:
	float* X;
	float* Y;
	int* radius;

public:
	/// <summary>
	/// Constructor of Circle Collider, takes in the memory addresses of
	/// x, y and radius of the game object that the collider is attached to
	/// </summary>
	/// <param name="x">: The centre x of the circle</param>
	/// <param name="y">: The centre y of the circle</param>
	/// <param name="radius">: The radius of the circle</param>
	CircleCollider(std::function<void(Collider*)> Response, float &x, float &y, int &radius);

	/// <summary>
	/// Getter for the circle colliders' centre x
	/// </summary>
	/// <returns>The centre x of the circle collider</returns>
	inline float GetCentreX() { return *X + *radius; }

	/// <summary>
	/// Getter for the circle colliders' centre y
	/// </summary>
	/// <returns>The centre y of the circle collider</returns>
	inline float GetCentreY() { return *Y + *radius; }

	/// <summary>
	/// Getter for the circle colliders' radius
	/// </summary>
	/// <returns>The radius of the circle collider</returns>
	inline int GetRadius() { return *radius; }
};

