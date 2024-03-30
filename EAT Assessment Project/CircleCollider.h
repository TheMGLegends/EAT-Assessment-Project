#pragma once

#include "Collider.h"

/// <summary>
/// Defines the circle collider class to be used by spherically shaped objects
/// </summary>
class CircleCollider : public Collider
{
private:
	int* radius;

public:
	/// <summary>
	/// Constructor of Circle Collider, takes in the memory addresses of
	/// x, y and radius of the game object that the collider is attached to
	/// as well as the response function that is called when a collision occurs
	/// </summary>
	/// <param name="Response">: The function to be bounded as the collision response</param>
	/// <param name="x">: The x-coordinate of the circle</param>
	/// <param name="y">: The y-coordinate of the circle</param>
	/// <param name="radius">: The radius of the circle</param>
	CircleCollider(std::function<void(Collider*)> Response, float &x, float &y, int &radius);

	/// <summary>
	/// Getter for the circle colliders' radius
	/// </summary>
	/// <returns>The radius of the circle collider</returns>
	inline int GetRadius() { return *radius; }

	/// <summary>
	/// Getter for the circle colliders' centre x
	/// </summary>
	/// <returns>The centre x of the circle collider</returns>
	inline float GetCentreX() override { return *X + *radius; }

	/// <summary>
	/// Getter for the circle colliders' centre y
	/// </summary>
	/// <returns>The centre y of the circle collider</returns>
	inline float GetCentreY() override { return *Y + *radius; }

};

