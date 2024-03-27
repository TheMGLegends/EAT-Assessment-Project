#include "CollisionManager.h"

#include <cmath>
#include <iostream>

#include "MemoryLeakDetector.h"

CollisionManager* CollisionManager::instance = nullptr;

void CollisionManager::Clean()
{
	// INFO: Clean all colliders
	for (int i = 0; i < colliders.size(); i++)
	{
		if (colliders[i] != nullptr)
		{
			delete colliders[i];
			colliders[i] = nullptr;
		}
	}

	// INFO: Clean up the instance
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}

void CollisionManager::CheckCollisions()
{
	// INFO: Used for comparing every collider with every other
	// collider in the list, excluding self-comparisons
	for (int i = 0; i < colliders.size(); i++)
	{
		for (int j = i + 1; j < colliders.size(); j++)
		{
			// INFO: Circle & Circle
			if (colliders[i]->GetColliderType() == ColliderType::Circle &&
				colliders[j]->GetColliderType() == ColliderType::Circle)
			{
				CircleCircleCollision(dynamic_cast<CircleCollider*>(colliders[i]), dynamic_cast<CircleCollider*>(colliders[j]));
			}
			// INFO: Rect & Rect
			else if (colliders[i]->GetColliderType() == ColliderType::Rect &&
				colliders[j]->GetColliderType() == ColliderType::Rect)
			{
				RectRectCollision(dynamic_cast<BoxCollider*>(colliders[i]), dynamic_cast<BoxCollider*>(colliders[j]));
			}
			// INFO: Rect & Circle
			else if (colliders[i]->GetColliderType() == ColliderType::Rect &&
				colliders[j]->GetColliderType() == ColliderType::Circle)
			{
				CircleRectCollision(dynamic_cast<CircleCollider*>(colliders[j]), dynamic_cast<BoxCollider*>(colliders[i]));
			}
			// INFO: Circle & Rect
			else if (colliders[i]->GetColliderType() == ColliderType::Circle &&
				colliders[j]->GetColliderType() == ColliderType::Rect)
			{
				CircleRectCollision(dynamic_cast<CircleCollider*>(colliders[i]), dynamic_cast<BoxCollider*>(colliders[j]));
			}
		}
	}
}

void CollisionManager::AddColliderToVector(Collider* c)
{
	colliders.push_back(c);
}

void CollisionManager::CircleCircleCollision(CircleCollider* c1, CircleCollider* c2)
{
	// INFO: The difference between the two circles' x and y coordinates
	float dx = c1->GetCentreX() - c2->GetCentreX();
	float dy = c1->GetCentreY() - c2->GetCentreY();

	// INFO: The sum of the two circles' radii
	int totalRadius = c1->GetRadius() + c2->GetRadius();

	// INFO: If the distance between the two circles is less than the
	// sum of their radii, then they are colliding
	if (std::sqrt(std::pow(dx, 2) + std::pow(dy, 2)) < totalRadius)
	{
		// INFO: Collision Detected
		// CALLBACKS FOR BOTH COLLIDERS PASSING IN THE OTHER COLLIDER AS PARAMETER
	}
}

void CollisionManager::RectRectCollision(BoxCollider* b1, BoxCollider* b2)
{
	// INFO: The min and max x and y values of the first box collider
	float b1MinX = b1->GetX();
	float b1MaxX = b1->GetX() + b1->GetWidth();

	float b1MinY = b1->GetY();
	float b1MaxY = b1->GetY() + b1->GetHeight();

	// INFO: The min and max x and y values of the second box collider
	float b2MinX = b2->GetX();
	float b2MaxX = b2->GetX() + b2->GetWidth();

	float b2MinY = b2->GetY();
	float b2MaxY = b2->GetY() + b2->GetHeight();

	if (b1MaxX > b2MinX && b1MinX < b2MaxX && b1MaxY > b2MinY && b1MinY < b2MaxY)
	{
		// INFO: Collision Detected
		// CALLBACKS FOR BOTH COLLIDERS PASSING IN THE OTHER COLLIDER AS PARAMETER
	}
}

void CollisionManager::CircleRectCollision(CircleCollider* c, BoxCollider* b)
{
	// INFO: Initializing for later use
	float closestX = 0;
	float closestY = 0;

	// INFO: Get the centre of the circle
	float cCentreX = c->GetCentreX();
	float cCentreY = c->GetCentreY();

	// INFO: Get the min and max x and y values of the box collider
	float bMinX = b->GetX();
	float bMaxX = b->GetX() + b->GetWidth();

	float bMinY = b->GetY();
	float bMaxY = b->GetY() + b->GetHeight();

	// INFO: Find the closest x value to the circle
	if (cCentreX < bMinX)
		closestX = bMinX;
	else if (cCentreX > bMaxX)
		closestX = bMaxX;
	else
		closestX = cCentreX;

	// INFO: Find the closest y value to the circle
	if (cCentreY < bMinY)
		closestY = bMinY;
	else if (cCentreY > bMaxY)
		closestY = bMaxY;
	else
		closestY = cCentreY;

	// INFO: The difference between the circle's centre and 
	// the closest x and y values
	float dx = cCentreX - closestX;
	float dy = cCentreY - closestY;

	// INFO: If the distance between the circle and closest x and y
	// is less than the circles' radius, then they are colliding
	if (std::sqrt(std::pow(dx, 2) + std::pow(dy, 2)) < c->GetRadius())
	{
		std::cout << "Hey hey, circle and rect are colliding!" << std::endl;
		// INFO: Collision Detected
		// CALLBACKS FOR BOTH COLLIDERS PASSING IN THE OTHER COLLIDER AS PARAMETER
	}
}
