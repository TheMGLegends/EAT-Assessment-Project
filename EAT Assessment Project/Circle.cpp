#include "Circle.h"

#include "AssetManager.h"

#include "MemoryLeakDetector.h"

Circle::Circle(Parameters* params, int radius) 
	: Shape(params)
{
	this->radius = radius;

	// INFO: Instantiate and Initialize the Circle Collider along with the bounded 
	// function that you want to call when a collision occurs
	circleCollider = new CircleCollider(std::bind(&Circle::OnCollisionEnter, this, std::placeholders::_1), position.X, position.Y, this->radius);

	// INFO: Specify the Shape Type to be Rectangle
	SetShapeType(ShapeType::Circle);
}

void Circle::Draw()
{
	AssetManager::DrawCircle(GetCentre(), radius, color);

	// INFO: Debug Outline for Showcasing Circle Collider
	AssetManager::DrawCircle(GetCentre(), radius, Color::RED, false);
}

