#include "Square.h"

#include "AssetManager.h"
#include "CircleCollider.h"

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

void Square::OnCollisionEnter(Collider* other)
{
	// INFO: Doesn't React to Collision if the object is static
	if (isStatic)
		return;

	// INFO: Switch Direction Based on Collision
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
	std::cout << "I am a square and I have just collided with another collider" << std::endl;

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

void Square::Update(float dt)
{
	position.Translate(moveDirection * moveSpeed * dt);
}

void Square::Draw()
{
	AssetManager::Instance()->DrawRect(GetID(), (int)position.X, (int)position.Y, size, size, color);
	
	// INFO: Debug Outline for Showcasing Box Collider
	AssetManager::Instance()->DrawBoxCollider((int)position.X, (int)position.Y, size, size);
}

void Square::Clean()
{
}

Transform Square::GetCentre()
{
	return Transform(position.X + size / 2, position.Y + size / 2);
}
