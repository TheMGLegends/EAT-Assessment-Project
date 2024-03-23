#include "Square.h"

#include "AssetManager.h"

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
	AssetManager::Instance()->DrawRect(GetID(), position.X, position.Y, size, size);
}

void Square::Clean()
{
	// INFO: Clean up Square Contents


	// INFO: Clean up Base Class Contents
	Shape::Clean();
}

Point Square::GetCentrePoint()
{
	return Point(position.X + size / 2, position.Y + size / 2);
}
