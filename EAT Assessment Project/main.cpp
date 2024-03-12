#include "SDL.h"

#include <iostream>

// TEMPORARY INCLUDES FOR TESTING
#include "Transform.h"
#include "Vector2.h"

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

	// TEMPORARY TESTING AREAS
	Transform t{};
	Vector2 v{ 5, 2 };
	t.Rotate(1);
	std::cout << std::endl;
	t.Up().DisplayXY();
	t.Right().DisplayXY();

	(void)getchar();

	SDL_DestroyWindow(sdlWindow);
	SDL_Quit();

	return 0;
}