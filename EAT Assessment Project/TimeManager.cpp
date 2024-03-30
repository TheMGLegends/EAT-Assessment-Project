#include "TimeManager.h"

#include <SDL.h>

#include "MemoryLeakDetector.h"

float TimeManager::deltaTime = 0;
float TimeManager::previousTime = 0;
float TimeManager::currentTime = 0;

void TimeManager::Initialize()
{
	// INFO: Initializes the previousTime and currentTime to the current time
	previousTime = (float)SDL_GetTicks();
	currentTime = previousTime;
}

void TimeManager::Tick()
{
	// INFO: Gets the current time
	currentTime = (float)SDL_GetTicks();

	// INFO: Subtracts the previous time from the current time to
	// get the time between frames (deltaTime) in seconds
	deltaTime = (currentTime - previousTime) / 1000;

	// INFO: Sets the old currentTime to the previousTime ready for
	// the next SDL_GetTicks call
	previousTime = currentTime;
}

