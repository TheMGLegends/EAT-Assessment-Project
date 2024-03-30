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
	/// <param name="params">: The parameters to be passed in</param>
	/// <param name="radius">: Radius of the circle</param>
	Circle(Parameters* params, int radius);

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
	Transform GetCentre() override;

	/// <summary>
	/// Getter for the circles' radius
	/// </summary>
	/// <returns>The radius of the circle</returns>
	inline int GetRadius() const { return radius; }

	// TEMP FUNCTION <--------------------------------------------------------------------------------------------------------------------------------------------
	inline void tempMoveXLeft() { position.X -= 5; }
};

