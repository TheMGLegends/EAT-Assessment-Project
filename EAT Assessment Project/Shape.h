#pragma once

#include "ICollision.h"

#include "Transform.h"
#include "Color.h"

#include <functional>

/// @brief An enum class to define the different types of shapes
enum class ShapeType
{
	None,

	Square,
	Rectangle,
	Circle
};

/// @brief A struct to hold the parameters to be passed in to 
/// initialize a shape object
struct Parameters
{
	float x;
	float y;
	bool isStatic;
	Color color;
	float moveSpeed;

	/// @brief The constructor for the parameters struct
	/// @param x : The x position of the shape
	/// @param y : The y position of the shape
	/// @param isStatic : Whether the shape is static or not
	/// @param color : The color of the shape
	/// @param moveSpeed : The speed at which the shape moves
	Parameters(float x, float y, bool isStatic = false, Color color = Color::GREEN, float moveSpeed = 100)
	{
		this->x = x;
		this->y = y;
		this->isStatic = isStatic;
		this->color = color;
		this->moveSpeed = moveSpeed;
	}
};

/// @brief Defines the base class for all shapes in the game
class Shape : public ICollision
{

private:
	ShapeType shapeType;

protected:
	Transform position;
	Vector2 moveDirection;
	Color color;

	bool isStatic;
	float moveSpeed;

public:
	/// @brief Shape Constructor
	/// @param params : The parameters to be passed in
	Shape(Parameters* params);

	/// @brief Inherited from the ICollision interface used for responding to collisions
	/// @param other : The other collider involved in the collision
	void OnCollisionEnter(Collider* other) override;

	/// @brief Updates values like the position of the shape
	/// @param dt : Delta Time
	virtual void Update(float dt);

	/// @brief Draws the shape from which this function is called from using the asset
	/// managers' drawing functionality
	virtual void Draw() = 0;

	/// @brief Getter for the centre point of the shape
	/// @return The centre point of the shape
	virtual Transform GetCentre() = 0;

	/// @brief Setter for the objects' is static variable
	/// @param isStatic : Whether the object should be static or not
	inline void SetIsStatic(bool isStatic) { this->isStatic = isStatic; }

	/// @brief Getter for the Shapes' Type
	/// @return The type of the shape the object is
	inline ShapeType GetShapeType() const { return shapeType; }

	/// @brief Setter for the Shapes' Type
	/// @param type : The type of shape
	inline void SetShapeType(ShapeType type) { shapeType = type; }

	/// @brief Getter for the color of the shape
	/// @return The R, G, B, A values of the color
	inline Color GetColor() const { return color; }
};

