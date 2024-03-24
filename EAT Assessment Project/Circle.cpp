#include "Circle.h"

#include "AssetManager.h"

#include "MemoryLeakDetector.h"

Circle::Circle(float x, float y, int radius, bool isStatic, Color color) 
	: Shape(x, y, isStatic, color)
{
	this->radius = radius;

	// INFO: Instantiate and Initialize the Box Collider
	circleCollider = new CircleCollider((int&)position.X, (int&)position.Y, this->radius);

	// INFO: Specify the Shape Type to be Rectangle
	SetShapeType(ShapeType::Circle);

	// INFO: Specify the Collider Type to be Circle
	circleCollider->SetColliderType(ColliderType::Circle);
}

void Circle::Update(float dt)
{
}

void Circle::Draw()
{
	AssetManager::Instance()->DrawCircle(GetCentrePoint(), radius, color);

	// INFO: Debug Outline for Showcasing Circle Collider
	AssetManager::Instance()->DrawCircle(GetCentrePoint(), radius, Color::RED, false);
}

void Circle::Clean()
{
	// INFO: Clean up Circle Contents
	if (circleCollider != nullptr)
	{
		delete circleCollider;
		circleCollider = nullptr;
	}
}

Point Circle::GetCentrePoint()
{
	return Point(position.X + radius, position.Y + radius);
}
