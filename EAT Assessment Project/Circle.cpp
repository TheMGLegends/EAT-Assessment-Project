#include "Circle.h"

#include "AssetManager.h"
#include "BoxCollider.h"

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

	if (other->GetY() < position.Y && moveDirection.Y < 0)
	{
		moveDirection.Y = 1;
	}
	else if (other->GetY() > position.Y && moveDirection.Y > 0)
	{
		moveDirection.Y = -1;
	}
	else if (other->GetX() < position.X && moveDirection.X < 0)
	{
		moveDirection.X = 1;
	}
	else if (other->GetX() > position.X && moveDirection.X > 0)
	{
		moveDirection.X = -1;
	}

	// INFO: Change Color of Shape on Collision
	color = Color::RandomColor();

	/*
	std::cout << "I am a circle and I have just collided with another collider" << std::endl;

	switch (other->GetColliderType())
	{
	case ColliderType::Rect:
	{
		BoxCollider* otherCollider = dynamic_cast<BoxCollider*>(other);

		if (otherCollider != nullptr)
		{
			std::cout << "The width of otherCollider is: " << otherCollider->GetWidth() << std::endl;
		}
	}
	break;
	case ColliderType::Circle:
	{
		CircleCollider* otherCollider = dynamic_cast<CircleCollider*>(other);

		if (otherCollider != nullptr)
		{
			std::cout << "The radius of otherCollider is: " << otherCollider->GetRadius() << std::endl;
		}
	}
	break;
	case ColliderType::None:
	default:
		break;
	}
	*/
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

void Circle::Clean()
{
}

Transform Circle::GetCentre()
{
	return Transform(position.X + radius, position.Y + radius);
}
