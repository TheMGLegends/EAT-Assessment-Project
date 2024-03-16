#include "EventManager.h"

EventManager* Singleton<EventManager>::instance = nullptr;

void EventManager::Clean()
{
	// INFO: Clean up the instance
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}
