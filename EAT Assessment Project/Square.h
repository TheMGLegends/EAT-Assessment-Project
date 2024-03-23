#pragma once

#include "Shape.h"

class Square : public Shape
{
private:
	int size;

public:
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="x">: X-Coordinate of the square</param>
	/// <param name="y">: Y-Coordinate of the square</param>
	/// <param name="size">: Size of the square</param>
	Square(float x, float y, float size);

	/// <summary>
	/// Updates the various values of the game object e.g. (rb values, position)
	/// </summary>
	/// <param name="dt">: Delta Time</param>
	void Update(float dt) override;

	/// <summary>
	/// Draws the square shape using the asset managers' drawing functionality
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
	/// Getter for the Squares' Size
	/// </summary>
	/// <returns>Size of the square</returns>
	inline int GetSize() const { return size; }
};

