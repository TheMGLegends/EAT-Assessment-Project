#pragma once

#include "Shape.h"

#include "CircleCollider.h"

class Circle : public Shape
{
private:
	CircleCollider* circleCollider;
	int radius;

public:
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="x">: X-Coordinate of the circle</param>
	/// <param name="y">: Y-Coordinate of the circle</param>
	/// <param name="radius">: Radius of the circle</param>
	Circle(float x, float y, int radius, bool isStatic = false, Color color = Color::GREEN);

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

	/// <summary>
	/// Gets the centre point of the shape
	/// </summary>
	Point GetCentrePoint() override;

	/// <summary>
	/// Getter for the circles' radius
	/// </summary>
	/// <returns>The radius of the circle</returns>
	inline int GetRadius() const { return radius; }

	// TEMP FUNCTION <--------------------------------------------------------------------------------------------------------------------------------------------
	inline void tempMoveXLeft() { position.X -= 5; }
};

