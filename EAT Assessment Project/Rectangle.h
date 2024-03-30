#pragma once

#include "Shape.h"

#include "BoxCollider.h"

/// <summary>
/// Defines the rectangle shape
/// </summary>
class Rectangle : public Shape
{
private:
	BoxCollider* boxCollider; // INFO: Gets deleted by collision manager
	int width;
	int height;

public:
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="params">: The parameters to be passed in</param>
	/// <param name="width">: Width of the rectangle</param>
	/// <param name="height">: Height of the rectangle</param>
	Rectangle(Parameters* params, int width, int height);

	/// <summary>
	/// Inherited from the ICollision interface used for responding to collisions
	/// </summary>
	/// <param name="other">: The other collider involved in the collision</param>
	void OnCollisionEnter(Collider* other) override;

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
	/// Getter for the centre point of the rectangle
	/// </summary>
	/// <returns>The centre point of the rectangle</returns>
	inline Transform GetCentre() override { return Transform(position.X + width / 2, position.Y + height / 2); }

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

