#include "Rectangle.h"

#include "AssetManager.h"
#include "PhysicsManager.h"
#include "CircleCollider.h"

#include "MemoryLeakDetector.h"

Rectangle::Rectangle(float x, float y, int width, int height, bool isStatic, Color color) 
	: Shape(x, y, isStatic, color)
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
}

void Rectangle::Update(float dt)
{
	PhysicsManager::Instance()->UpdatePhysics(rb, dt);

	previousPosition.X = position.X;
	position.TranslateX(rb.displacement.X);
	
	previousPosition.Y = position.Y;
	position.TranslateY(rb.displacement.Y);
}

void Rectangle::Draw()
{
	AssetManager::Instance()->DrawRect(GetID(), (int)position.X, (int)position.Y, width, height);

	// INFO: Debug Outline for Showcasing Box Collider
	AssetManager::Instance()->DrawBoxCollider((int)position.X, (int)position.Y, width, height);
}

void Rectangle::Clean()
{
}

Point Rectangle::GetCentrePoint()
{
	return Point(position.X + width / 2, position.Y + height / 2);
}
