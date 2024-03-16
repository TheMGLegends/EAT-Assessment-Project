#include "CollisionManager.h"

CollisionManager* Singleton<CollisionManager>::instance = nullptr;

void CollisionManager::Clean()
{
	// INFO: Clean up the instance
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}
