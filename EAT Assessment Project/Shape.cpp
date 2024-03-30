#include "Shape.h"

#include "MemoryLeakDetector.h"

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

