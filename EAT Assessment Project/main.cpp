#include "SDL.h"

#include <iostream>

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "Failed to initialise SDL. SDL error: " << SDL_GetError() << std::endl;
	}

	SDL_Window* sdlWindow = SDL_CreateWindow("Engine Architecture and Tools Assessment Project", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, NULL);

	if (sdlWindow == nullptr)
	{
		std::cout << "Failed to create window. SDL error: " << SDL_GetError() << std::endl;
	}

	(void)getchar();

	SDL_DestroyWindow(sdlWindow);
	SDL_Quit();

	return 0;
}