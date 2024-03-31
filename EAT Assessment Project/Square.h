#pragma once

#include "Shape.h"

#include "BoxCollider.h"

/// <summary>
/// Defines the square shape
/// </summary>
class Square : public Shape
{
private:
	BoxCollider* boxCollider; // INFO: Gets deleted by collision manager
	int size;

public:
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="params">: The parameters to be passed in</param>
	/// <param name="size">: Size of the square</param>
	Square(Parameters* params, int size);

	/// <summary>
	/// Draws the square shape using the asset managers' drawing functionality
	/// </summary>
	void Draw() override;

	/// <summary>
	/// Getter for the centre point of the square
	/// </summary>
	/// <returns>The centre point of the square</returns>
	inline Transform GetCentre() override { return Transform(position.X + size / 2, position.Y + size / 2); }

	/// <summary>
	/// Getter for the Squares' Size
	/// </summary>
	/// <returns>Size of the square</returns>
	inline int GetSize() const { return size; }
};

