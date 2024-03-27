#include "Rectangle.h"

#include "AssetManager.h"

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
	std::cout << "I am a rectangle and I have just collided with another collider" << std::endl;
}

void Rectangle::Update(float dt)
{
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
