#include "Shape.h"

#include "MemoryLeakDetector.h"

int Shape::shapeCount = 0;

Shape::Shape(float x, float y, bool isStatic, Color color)
{
	this->isStatic = isStatic;
	this->color = color;

	// INFO: Set the position of the shape
	position.X = x;
	position.Y = y;

	// INFO: Set the ID of the shape based on
	// the current shape count
	id = shapeCount;

	// INFO: Increment shape count ready for the
	// next shape to set it as their ID
	shapeCount++;

	// INFO: Set Shape Type to None ready for it 
	// to be set in the derived classes constructors
	shapeType = ShapeType::None;
}
