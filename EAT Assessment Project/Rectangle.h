#pragma once

#include "Shape.h"

#include "BoxCollider.h"

/// @brief Defines the rectangle shape
class Rectangle : public Shape
{
private:
	BoxCollider* boxCollider; // INFO: Gets deleted by collision manager
	int width;
	int height;

public:
	/// @brief Rectangle Constructor
	/// @param params : The parameters to be passed in
	/// @param width : Width of the rectangle
	/// @param height : Height of the rectangle
	Rectangle(Parameters* params, int width, int height);

	/// @brief Draws the rectangle shape using the asset managers' drawing functionality
	void Draw() override;

	/// @brief Getter for the centre point of the rectangle
	/// @return The centre point of the rectangle
	inline Transform GetCentre() override { return Transform(position.X + width / 2, position.Y + height / 2); }

	/// @brief Getter for the Rectangles' Width
	/// @return The width of the rectangle
	inline int GetWidth() const { return width; }

	/// @brief Getter for the Rectangles' Height
	/// @return The height of the rectangle
	inline int GetHeight() const { return height; }
};

