#pragma once

#include "Shape.h"

#include "BoxCollider.h"

class Square : public Shape
{
private:
	BoxCollider* boxCollider;
	int size;

public:
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="params">: The parameters to be passed in</param>
	/// <param name="size">: Size of the square</param>
	Square(Parameters* params, int size);

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
	Transform GetCentre() override;

	/// <summary>
	/// Getter for the Squares' Size
	/// </summary>
	/// <returns>Size of the square</returns>
	inline int GetSize() const { return size; }

	// TEMP FUNCTION <--------------------------------------------------------------------------------------------------------------------------------------------
	inline void tempMoveXLeft() { position.X -= 5; }
};

