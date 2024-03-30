#include "Rectangle.h"

#include "AssetManager.h"
#include "PhysicsManager.h"
#include "CircleCollider.h"

#include "MemoryLeakDetector.h"

Rectangle::Rectangle(Parameters* params, int width, int height)
	: Shape(params)
{
	// INFO: Check to ensure width and height aren't the same
	// otherwise it would be a Square
	if (width == height)
	{
		// INFO: Adjust one dimension slightly to make it
		// a rectangle
		height++;
	}

	this->width = width;
	this->height = height;

	// INFO: Instantiate and Initialize the Box Collider along with the bounded 
	// function that you want to call when a collision occurs
	boxCollider = new BoxCollider(std::bind(&Rectangle::OnCollisionEnter, this, std::placeholders::_1), position.X, position.Y, this->width, this->height);

	// INFO: Specify the Shape Type to be Rectangle
	SetShapeType(ShapeType::Rectangle);

	// INFO: Specify the Collider Type to be Rect
	boxCollider->SetColliderType(ColliderType::Rect);
}

void Rectangle::OnCollisionEnter(Collider* other)
{
	// INFO: Doesn't React to Collision if the object is static
	if (isStatic)
		return;

	if (other->GetY() < position.Y && moveDirection.Y < 0)
	{
		moveDirection.Y = 1;
	}
	else if (other->GetY() > position.Y  && moveDirection.Y > 0)
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
	std::cout << "I am a rectangle and I have just collided with another collider" << std::endl;

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

void Rectangle::Update(float dt)
{
	position.Translate(moveDirection * moveSpeed * dt);
}

void Rectangle::Draw()
{
	AssetManager::Instance()->DrawRect(GetID(), (int)position.X, (int)position.Y, width, height, color);

	// INFO: Debug Outline for Showcasing Box Collider
	AssetManager::Instance()->DrawBoxCollider((int)position.X, (int)position.Y, width, height);
}

void Rectangle::Clean()
{
}

Transform Rectangle::GetCentre()
{
	return Transform(position.X + width / 2, position.Y + height / 2);
}
