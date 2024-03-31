#pragma once

#include "Shape.h"

#include "CircleCollider.h"

/// <summary>
/// Defines the circle shape
/// </summary>
class Circle : public Shape
{
private:
	CircleCollider* circleCollider; // INFO: Gets deleted by collision manager
	int radius;

public:
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="params">: The parameters to be passed in</param>
	/// <param name="radius">: Radius of the circle</param>
	Circle(Parameters* params, int radius);

	/// <summary>
	/// Draws the circle shape using the asset managers' drawing functionality
	/// </summary>
	void Draw() override;

	/// <summary>
	/// Getter for the centre point of the circle
	/// </summary>
	/// <returns>The centre point of the circle</returns>
	inline Transform GetCentre() override { return Transform(position.X + radius, position.Y + radius); }

	/// <summary>
	/// Getter for the circles' radius
	/// </summary>
	/// <returns>The radius of the circle</returns>
	inline int GetRadius() const { return radius; }
};

