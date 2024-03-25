#include "Square.h"

#include "AssetManager.h"

#include "MemoryLeakDetector.h"

Square::Square(float x, float y, int size, bool isStatic, Color color) 
	: Shape(x, y, isStatic, color)
{
	this->size = size;

	// INFO: Instantiate and Initialize the Box Collider
	boxCollider = new BoxCollider(position.X, position.Y, this->size, this->size);

	// INFO: Specify the Shape Type to be Square
	SetShapeType(ShapeType::Square);

	// INFO: Specify the Collider Type to be Rect
	boxCollider->SetColliderType(ColliderType::Rect);
}

void Square::Update(float dt)
{
}

void Square::Draw()
{
	AssetManager::Instance()->DrawRect(GetID(), (int)position.X, (int)position.Y, size, size);
	
	// INFO: Debug Outline for Showcasing Box Collider
	AssetManager::Instance()->DrawBoxCollider((int)position.X, (int)position.Y, size, size);
}

void Square::Clean()
{
	// INFO: Clean up Square Contents
	if (boxCollider != nullptr)
	{
		delete boxCollider;
		boxCollider = nullptr;
	}
}

Point Square::GetCentrePoint()
{
	return Point(position.X + size / 2, position.Y + size / 2);
}
