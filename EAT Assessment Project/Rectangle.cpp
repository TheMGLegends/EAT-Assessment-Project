#include "Rectangle.h"

#include "AssetManager.h"
#include "PhysicsManager.h"
#include "CircleCollider.h"

#include "MemoryLeakDetector.h"

Rectangle::Rectangle(Parameters* params, int width, int height)
	: Shape(params)
{
	this->width = width;
	this->height = height;

	// INFO: Instantiate and Initialize the Box Collider along with the bounded 
	// function that you want to call when a collision occurs
	boxCollider = new BoxCollider(std::bind(&Rectangle::OnCollisionEnter, this, std::placeholders::_1), position.X, position.Y, this->width, this->height);

	// INFO: Specify the Shape Type to be Rectangle
	SetShapeType(ShapeType::Rectangle);
}

void Rectangle::Draw()
{
	AssetManager::DrawRect((int)position.X, (int)position.Y, width, height, color);

	// INFO: Debug Outline for Showcasing Box Collider
	AssetManager::DrawBoxCollider((int)position.X, (int)position.Y, width, height);
}

