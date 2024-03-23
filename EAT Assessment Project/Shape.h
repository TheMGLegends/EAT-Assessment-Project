#pragma once

#include "EventListener.h"

#include "Transform.h"
#include "Rigidbody.h"
#include "Collider.h"

#include "Program.h"

enum class ShapeType
{
	None,

	Square,
	Rectangle,
	Circle
};

class Shape : public EventListener
{

private:
	static int shapeCount;
	int id;
	ShapeType shapeType;

protected:
	Transform position;
	Transform futurePosition;
	Rigidbody rb;
	Collider* collider;
	Color color;

public:
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="x">: X-Coordinate of the shape</param>
	/// <param name="y">: Y-Coordinate of the shape</param>
	Shape(float x, float y);

	/// <summary>
	/// Updates the various values of the game object e.g. (rb values, position)
	/// </summary>
	/// <param name="dt">: Delta Time</param>
	virtual void Update(float dt) = 0;

	/// <summary>
	/// Draws the shape from which this function is called from using the asset
	/// managers' drawing functionality
	/// </summary>
	virtual void Draw() = 0;

	/// <summary>
	/// Clean up method during program termination
	/// </summary>
	virtual void Clean();

	/// <summary>
	/// Gets the centre point of the shape
	/// </summary>
	virtual Point GetCentrePoint() = 0;

	/// <summary>
	/// Getter for the Shapes' ID
	/// </summary>
	/// <returns>The ID of the Shape</returns>
	inline int GetID() const { return id; }

	/// <summary>
	/// Getter for the Shapes' Type
	/// </summary>
	/// <returns>The type of the shape the object is</returns>
	inline ShapeType GetShapeType() const { return shapeType; }

	/// <summary>
	/// Setter for the Shapes' Type
	/// </summary>
	/// <param name="type">: The type of shape</param>
	inline void SetShapeType(ShapeType type) { shapeType = type; }

	/// <summary>
	/// Getter for the Color Values
	/// </summary>
	/// <returns>The R, G, B, A values</returns>
	inline Color GetColor() const { return color; }
};

