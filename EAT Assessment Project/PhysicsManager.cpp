#include "PhysicsManager.h"

PhysicsManager* Singleton<PhysicsManager>::instance = nullptr;

void PhysicsManager::Clean()
{
	// INFO: Clean up the instance
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}
