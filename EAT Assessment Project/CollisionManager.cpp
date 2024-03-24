#include "CollisionManager.h"

#include "MemoryLeakDetector.h"

CollisionManager* Singleton<CollisionManager>::instance = nullptr;

CollisionManager::CollisionManager()
{
}

void CollisionManager::Clean()
{
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

			}
			// INFO: Rect & Rect
			else if (colliders[i]->GetColliderType() == ColliderType::Rect &&
				colliders[j]->GetColliderType() == ColliderType::Rect)
			{

			}
			// INFO: Rect & Circle
			else if (colliders[i]->GetColliderType() == ColliderType::Rect &&
				colliders[j]->GetColliderType() == ColliderType::Circle)
			{

			}
			// INFO: Circle & Rect
			else if (colliders[i]->GetColliderType() == ColliderType::Circle &&
				colliders[j]->GetColliderType() == ColliderType::Rect)
			{

			}
		}
	}
}
