#include "SDL.h"

#include "MemoryLeakDetector.h"

#include <iostream>

// TEMPORARY INCLUDES FOR TESTING


int main(int argc, char* argv[])
{
	// INFO: Detection Flags for Memory Leaks
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "Failed to initialise SDL. SDL error: " << SDL_GetError() << std::endl;
	}

	SDL_Window* sdlWindow = SDL_CreateWindow("Engine Architecture and Tools Assessment Project", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, NULL);

	if (sdlWindow == nullptr)
	{
		std::cout << "Failed to create window. SDL error: " << SDL_GetError() << std::endl;
	}

	// TEMPORARY TESTING AREAS


	(void)getchar();

	SDL_DestroyWindow(sdlWindow);
	SDL_Quit();

	return 0;
}