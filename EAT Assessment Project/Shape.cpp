#include "Shape.h"

#include "MemoryLeakDetector.h"

int Shape::shapeCount = 0;

Shape::Shape(Parameters* params)
{
	// INFO: Set the position of the shape
	position.X = params->x;
	position.Y = params->y;

	this->isStatic = params->isStatic;
	this->color = params->color;
	this->moveSpeed = params->moveSpeed;

	// INFO: Randomize the initial move direction
	moveDirection = Vector2::RandomDirection();

	// INFO: Set the ID of the shape based on
	// the current shape count
	id = shapeCount;

	// INFO: Increment shape count ready for the
	// next shape to set it as their ID
	shapeCount++;

	// INFO: Set Shape Type to None ready for it 
	// to be set in the derived classes constructors
	shapeType = ShapeType::None;

	// INFO: Delete dynamically created parameters
	if (params != nullptr)
	{
		delete params;
		params = nullptr;
	}
}

