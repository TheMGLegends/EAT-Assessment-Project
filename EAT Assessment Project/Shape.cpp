#include "Shape.h"

#include "MemoryLeakDetector.h"

Shape::Shape(Parameters* params)
{
	// INFO: Set the position of the shape
	position.X = params->x;
	position.Y = params->y;

	this->isStatic = params->isStatic;
	this->color = params->color;
	this->moveSpeed = params->moveSpeed;

	// INFO: Randomize the initial move direction
	moveDirection = Vector2::RandomDirection();

	// INFO: Set Shape Type to None ready for it 
	// to be set in the derived classes constructors
	shapeType = ShapeType::None;

	// INFO: Delete dynamically created parameters
	if (params != nullptr)
	{
		delete params;
		params = nullptr;
	}
}

void Shape::OnCollisionEnter(Collider* other)
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

void Shape::Update(float dt)
{
	position.Translate(moveDirection * moveSpeed * dt);
}

