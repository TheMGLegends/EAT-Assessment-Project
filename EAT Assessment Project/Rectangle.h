#pragma once

#include "Shape.h"

#include "BoxCollider.h"

class Rectangle : public Shape
{
private:
	BoxCollider* boxCollider;
	int width;
	int height;

public:
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="x">: X-Coordinate of the square</param>
	/// <param name="y">: Y-Coordinate of the square</param>
	/// <param name="width">: Width of the rectangle</param>
	/// <param name="height">: Height of the rectangle</param>
	Rectangle(float x, float y, int width, int height, bool isStatic = false, Color color = GREEN);

	/// <summary>
	/// Updates the various values of the game object e.g. (rb values, position)
	/// </summary>
	/// <param name="dt">: Delta Time</param>
	void Update(float dt) override;

	/// <summary>
	/// Draws the rectangle shape using the asset managers' drawing functionality
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
	/// Getter for the Rectangles' Width
	/// </summary>
	/// <returns>The width of the rectangle</returns>
	inline int GetWidth() const { return width; }

	/// <summary>
	/// Getter for the Rectangles' Height
	/// </summary>
	/// <returns>The height of the rectangle</returns>
	inline int GetHeight() const { return height; }
};

