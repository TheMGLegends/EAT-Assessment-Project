#include "Square.h"

#include "AssetManager.h"

#include "MemoryLeakDetector.h"

Square::Square(Parameters* params, int size) 
	: Shape(params)
{
	this->size = size;

	// INFO: Instantiate and Initialize the Box Collider along with the bounded 
	// function that you want to call when a collision occurs
	boxCollider = new BoxCollider(std::bind(&Square::OnCollisionEnter, this, std::placeholders::_1), position.X, position.Y, this->size, this->size);

	// INFO: Specify the Shape Type to be Square
	SetShapeType(ShapeType::Square);

	// INFO: Specify the Collider Type to be Rect
	boxCollider->SetColliderType(ColliderType::Rect);
}

void Square::Draw()
{
	AssetManager::DrawRect((int)position.X, (int)position.Y, size, size, color);
	
	// INFO: Debug Outline for Showcasing Box Collider
	AssetManager::DrawBoxCollider((int)position.X, (int)position.Y, size, size);
}

