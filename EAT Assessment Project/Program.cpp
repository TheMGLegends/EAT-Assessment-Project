#include "Program.h"

#include "InputManager.h"
#include "TimeManager.h"

#include "SDL_image.h"

#include <iostream>

Program* Singleton<Program>::instance = nullptr;

Program::Program() :
	window{ nullptr },
	renderer{ nullptr },
	isRunning{ false }
{
}

void Program::Clean()
{
	// INFO: Clean Managers
	InputManager::Instance()->Clean();
	TimeManager::Instance()->Clean();

	// INFO: Destroys the SDL renderer & window
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	// INFO: Unloads the SDL Image Library
	IMG_Quit();

	// INFO: Unloads the main SDL Library
	SDL_Quit();

	// INFO: Clean up the instance
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}

bool Program::Initialize(const char* WINDOW_TITLE, int screenWidth, int screenHeight)
{
	// INFO: Initialize and Verify the SDL Library
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "Failed to initialize SDL. SDL Error: " << SDL_GetError() << std::endl;
		return false;
	}

	// INFO: Initialize and Verify the SDL Image Library
	int flags = IMG_INIT_JPG | IMG_INIT_PNG;

	if (IMG_Init(flags) != flags)
	{
		std::cout << "Failed to initialize SDL Image. SDL Image Error: " << IMG_GetError() << std::endl;
		return false;
	}
	
	// INFO: Create and Verify SDL Window
	window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
							  screenWidth, screenHeight, NULL);

	if (window == nullptr)
	{
		std::cout << "Failed to create window. SDL Error: " << SDL_GetError() << std::endl;
		return false;
	}

	// INFO: Create and Verify SDL Renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (renderer == nullptr)
	{
		std::cout << "Failed to create renderer. SDL Error: " << SDL_GetError() << std::endl;
		return false;
	}

	// INFO: Set the Initial Screen Color (White and Fully Opaque)
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	// INFO: Activate Program Loop
	isRunning = true;

	return isRunning;
}

void Program::HandleInput()
{
	InputManager::Instance()->PollEvents();
}

void Program::ProcessEvents()
{
}

void Program::Update(float dt)
{
}

void Program::Draw()
{
	// INFO: Clear the renderer ready for the next frame to be shown
	SDL_RenderClear(renderer);

	

	// INFO: Present the new frame to the screen
	SDL_RenderPresent(renderer);
}

