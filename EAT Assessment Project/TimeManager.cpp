#include "TimeManager.h"

#include <SDL.h>

#include "MemoryLeakDetector.h"

TimeManager* Singleton<TimeManager>::instance = nullptr;

TimeManager::TimeManager() :
	deltaTime{ 0 },
	previousTime{ 0 },
	currentTime{ 0 }
{
}

void TimeManager::Clean()
{
	// INFO: Clean up the instance
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}

void TimeManager::Tick()
{
	// INFO: Gets the current time
	currentTime = (float)SDL_GetTicks();

	// INFO: Subtracts the previous time from the current time to
	// get the time between frames (deltaTime) in seconds
	deltaTime = (currentTime - previousTime) / MILLISECONDS_IN_SECOND;

	// INFO: Sets the old currentTime to the previousTime ready for
	// the next SDL_GetTicks call
	previousTime = currentTime;
}

