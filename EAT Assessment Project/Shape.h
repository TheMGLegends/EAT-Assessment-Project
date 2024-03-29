#pragma once

#include "ICollision.h"

#include "Transform.h"
#include "Rigidbody.h"

#include "Color.h"

#include <functional>

enum class ShapeType
{
	None,

	Square,
	Rectangle,
	Circle
};

class Shape : public ICollision
{

private:
	static int shapeCount;
	int id;
	ShapeType shapeType;

protected:
	Transform position;
	Transform previousPosition;
	Rigidbody rb;
	Color color;
	bool isStatic;

public:
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="x">: X-Coordinate of the shape</param>
	/// <param name="y">: Y-Coordinate of the shape</param>
	Shape(float x, float y, bool isStatic = false, Color color = Color::GREEN);

	/// <summary>
	/// Inherited from the ICollision interface used for responding to collisions
	/// </summary>
	/// <param name="other">: The other collider involved in the collision</param>
	virtual void OnCollisionEnter(Collider* other) = 0;

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
	virtual void Clean() = 0;

	/// <summary>
	/// Gets the centre point of the shape
	/// </summary>
	virtual Point GetCentrePoint() = 0;

	/// <summary>
	/// Setter for the GOs is static variable
	/// </summary>
	/// <param name="isStatic">: Whether the GO should be static or not</param>
	inline void SetIsStatic(bool isStatic) { this->isStatic = isStatic; }

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

