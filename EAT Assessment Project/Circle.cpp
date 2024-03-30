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

	// INFO: Specify the Collider Type to be Circle
	circleCollider->SetColliderType(ColliderType::Circle);
}

void Circle::OnCollisionEnter(Collider* other)
{
	// INFO: Doesn't React to Collision if the object is static
	if (isStatic)
		return;

	// INFO: Change Direction on Collision
	if (other->GetCentreY() < position.Y && moveDirection.Y < 0)
	{
		moveDirection.Y = 1;
	}
	else if (other->GetCentreY() > position.Y && moveDirection.Y > 0)
	{
		moveDirection.Y = -1;
	}
	else if (other->GetCentreX() < position.X && moveDirection.X < 0)
	{
		moveDirection.X = 1;
	}
	else if (other->GetCentreX() > position.X && moveDirection.X > 0)
	{
		moveDirection.X = -1;
	}

	// INFO: Change Color of Shape on Collision
	color = Color::RandomColor();
}

void Circle::Update(float dt)
{
	position.Translate(moveDirection * moveSpeed * dt);
}

void Circle::Draw()
{
	AssetManager::Instance()->DrawCircle(GetCentre(), radius, color);

	// INFO: Debug Outline for Showcasing Circle Collider
	AssetManager::Instance()->DrawCircle(GetCentre(), radius, Color::RED, false);
}

