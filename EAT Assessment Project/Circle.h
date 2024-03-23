#pragma once

#include "Shape.h"

class Circle : public Shape
{
private:
	float radius;

public:
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="x">: X-Coordinate of the circle</param>
	/// <param name="y">: Y-Coordinate of the circle</param>
	/// <param name="radius">: Radius of the circle</param>
	Circle(float x, float y, float radius);

	/// <summary>
	/// Updates the various values of the game object e.g. (rb values, position)
	/// </summary>
	/// <param name="dt">: Delta Time</param>
	void Update(float dt) override;

	/// <summary>
	/// Draws the circle shape using the asset managers' drawing functionality
	/// </summary>
	void Draw() override;

	/// <summary>
	/// Clean up method during program termination
	/// </summary>
	void Clean() override;
};

