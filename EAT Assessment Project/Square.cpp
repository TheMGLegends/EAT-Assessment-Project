#include "Square.h"

#include "AssetManager.h"

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

