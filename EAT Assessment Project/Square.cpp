#include "Square.h"

#include "AssetManager.h"
#include "CircleCollider.h"

#include "MemoryLeakDetector.h"

Square::Square(float x, float y, int size, bool isStatic, Color color) 
	: Shape(x, y, isStatic, color)
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
}

void Square::Update(float dt)
{
}

void Square::Draw()
{
	AssetManager::Instance()->DrawRect(GetID(), (int)position.X, (int)position.Y, size, size);
	
	// INFO: Debug Outline for Showcasing Box Collider
	AssetManager::Instance()->DrawBoxCollider((int)position.X, (int)position.Y, size, size);
}

void Square::Clean()
{
}

Point Square::GetCentrePoint()
{
	return Point(position.X + size / 2, position.Y + size / 2);
}
