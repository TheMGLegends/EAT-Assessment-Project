#include "Circle.h"

#include "AssetManager.h"

#include "MemoryLeakDetector.h"

Circle::Circle(float x, float y, int radius) : Shape(x, y)
{
	this->radius = radius;

	// INFO: Specify the Shape Type to be Rectangle
	SetShapeType(ShapeType::Circle);

	// INFO: Specify the Collider Type to be Circle
	collider->SetColliderType(ColliderType::Circle);
}

void Circle::Update(float dt)
{
}

void Circle::Draw()
{
	AssetManager::Instance()->DrawCircle(GetID(), color);
}

void Circle::Clean()
{
	// INFO: Clean up Circle Contents


	// INFO: Clean up Base Class Contents
	Shape::Clean();
}

Point Circle::GetCentrePoint()
{
	return Point(position.X + radius, position.Y + radius);
}
