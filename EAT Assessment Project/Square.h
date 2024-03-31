#pragma once

#include "Shape.h"

#include "BoxCollider.h"

/// @brief Defines the square shape
class Square : public Shape
{
private:
	BoxCollider* boxCollider; // INFO: Gets deleted by collision manager
	int size;

public:
	/// @brief Square Constructor
	/// @param params : The parameters to be passed in
	/// @param size : Size of the square
	Square(Parameters* params, int size);

	/// @brief Draws the square shape using the asset managers' drawing functionality
	void Draw() override;

	/// @brief Getter for the centre point of the square
	/// @return The centre point of the square
	inline Transform GetCentre() override { return Transform(position.X + size / 2, position.Y + size / 2); }

	/// @brief Getter for the size of the square
	/// @return The size of the square
	inline int GetSize() const { return size; }
};

