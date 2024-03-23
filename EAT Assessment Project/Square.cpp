#include "Square.h"

#include "MemoryLeakDetector.h"

Square::Square(float x, float y, float size) : Shape(x, y)
{
	this->size = size;

	// INFO: Specify the Shape Type to be Square
	SetShapeType(ShapeType::Square);

	// INFO: Specify the Collider Type to be Rect
	collider->SetColliderType(ColliderType::Rect);
}

void Square::Update(float dt)
{
}

void Square::Draw()
{
}

void Square::Clean()
{
	// INFO: Clean up Square Contents


	// INFO: Clean up Base Class Contents
	Shape::Clean();
}
