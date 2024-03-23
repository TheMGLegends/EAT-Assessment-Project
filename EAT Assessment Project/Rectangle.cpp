#include "Rectangle.h"

#include "MemoryLeakDetector.h"

Rectangle::Rectangle(float x, float y, int width, int height) : Shape(x, y)
{
	// INFO: Check to ensure width and height aren't the same
	// otherwise it would be a Square
	if (width == height)
	{
		// INFO: Adjust one dimension slightly to make it
		// a rectangle
		height++;
	}

	this->width = width;
	this->height = height;

	// INFO: Specify the Shape Type to be Rectangle
	SetShapeType(ShapeType::Rectangle);

	// INFO: Specify the Collider Type to be Rect
	collider->SetColliderType(ColliderType::Rect);
}

void Rectangle::Update(float dt)
{
}

void Rectangle::Draw()
{
}

void Rectangle::Clean()
{
	// INFO: Clean up Rectangle Contents


	// INFO: Clean up Base Class Contents
	Shape::Clean();
}
