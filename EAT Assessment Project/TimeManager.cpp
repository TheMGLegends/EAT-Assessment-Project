#include "TimeManager.h"

TimeManager* Singleton<TimeManager>::instance = nullptr;

void TimeManager::Clean()
{
	// INFO: Clean up the instance
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}
