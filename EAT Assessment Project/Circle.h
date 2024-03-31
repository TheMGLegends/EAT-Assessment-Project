#pragma once

#include "Shape.h"

#include "CircleCollider.h"

/// @brief Defines the circle shape
class Circle : public Shape
{
private:
	CircleCollider* circleCollider; // INFO: Gets deleted by collision manager
	int radius;

public:
	/// @brief Circle Constructor
	/// @param params : The parameters to be passed in
	/// @param radius : Radius of the circle
	Circle(Parameters* params, int radius);

	/// @brief Draws the circle shape using the asset managers' drawing functionality
	void Draw() override;

	/// @brief Getter for the centre point of the circle
	/// @return The centre point of the circle
	inline Transform GetCentre() override { return Transform(position.X + radius, position.Y + radius); }

	/// @brief Getter for the radius of the circle
	/// @return The radius of the circle
	inline int GetRadius() const { return radius; }
};

