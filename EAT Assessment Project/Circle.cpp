#include "Circle.h"

#include "AssetManager.h"

#include "MemoryLeakDetector.h"

Circle::Circle(float x, float y, int radius, bool isStatic, Color color) 
	: Shape(x, y, isStatic, color)
{
	this->radius = radius;

	// INFO: Instantiate and Initialize the Circle Collider along with the bounded 
	// function that you want to call when a collision occurs
	circleCollider = new CircleCollider(std::bind(&Circle::OnCollisionEnter, this, std::placeholders::_1), position.X, position.Y, this->radius);

	// INFO: Specify the Shape Type to be Rectangle
	SetShapeType(ShapeType::Circle);

	// INFO: Specify the Collider Type to be Circle
	circleCollider->SetColliderType(ColliderType::Circle);
}

void Circle::OnCollisionEnter(Collider* other)
{
	std::cout << "I am a circle and I have just collided with another collider" << std::endl;
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
}

Point Circle::GetCentrePoint()
{
	return Point(position.X + radius, position.Y + radius);
}
