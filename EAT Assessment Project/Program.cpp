#include "Program.h"

#include "InputManager.h"
#include "AssetManager.h"

#include "SDL_image.h"

#include <iostream>

// TESTING INCLUDES <--------------------------------------------------------------------------------------------------------------------------------------------
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"

Program* Singleton<Program>::instance = nullptr;

// TESTING GAME OBJECTS <--------------------------------------------------------------------------------------------------------------------------------------------
Square* square = nullptr;
Rectangle* rectangle = nullptr;
Circle* circle = nullptr;

Program::Program() :
	window{ nullptr },
	renderer{ nullptr },
	isRunning{ false },
	screenColor{ Color::WHITE }
{
}

void Program::Clean()
{
	// INFO: Clean Managers
	InputManager::Clean();
	AssetManager::Instance()->Clean();

	// TESTING DELETE GAME OBJECTS <--------------------------------------------------------------------------------------------------------------------------------------------
	if (square != nullptr)
	{
		square->Clean();
		delete square;
		square = nullptr;
	}

	if (rectangle != nullptr)
	{
		rectangle->Clean();
		delete rectangle;
		rectangle = nullptr;
	}

	if (circle != nullptr)
	{
		circle->Clean();
		delete circle;
		circle = nullptr;
	}

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

	// INFO: Set the Initial Screen Color
	SDL_SetRenderDrawColor(renderer, screenColor.R, screenColor.G, screenColor.B, screenColor.A);

	// INFO: Activate Program Loop
	isRunning = true;

	// INFO: Initialize Input Manager
	InputManager::Initialize();

	// TESTING INITIALIZATION OF GAME OBJECTS <--------------------------------------------------------------------------------------------------------------------------------------------
	square = new Square(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 20);
	rectangle = new Rectangle(SCREEN_WIDTH / 4, SCREEN_HEIGHT / 2, 50, 100);
	circle = new Circle(SCREEN_WIDTH * 0.75f, SCREEN_HEIGHT / 2, 100);

	AssetManager::Instance()->LoadTexture(square, renderer);
	AssetManager::Instance()->LoadTexture(rectangle, renderer);

	return isRunning;
}

void Program::HandleInput()
{
	InputManager::PollEvents();

	// TEMP TESTING <--------------------------------------------------------------------------------------------------------------------------------------------
	if (InputManager::GetKeyDown(SDL_SCANCODE_A))
		circle->tempMoveXLeft();
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

	// TEST DRAWING GAME OBJECTS <--------------------------------------------------------------------------------------------------------------------------------------------
	square->Draw();
	rectangle->Draw();
	circle->Draw();

	// INFO: Present the new frame to the screen
	SDL_RenderPresent(renderer);
}

void Program::DefaultScreenColor()
{
	SDL_SetRenderDrawColor(renderer, screenColor.R, screenColor.G, screenColor.B, screenColor.A);
}
