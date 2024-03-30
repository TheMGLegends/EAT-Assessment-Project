#include "Program.h"

#include "InputManager.h"
#include "AssetManager.h"
#include "CollisionManager.h"
#include "PhysicsManager.h"

#include "SDL_image.h"

#include <iostream>

// TESTING INCLUDES <--------------------------------------------------------------------------------------------------------------------------------------------
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"

Program* Singleton<Program>::instance = nullptr;

// TESTING GAME OBJECTS <--------------------------------------------------------------------------------------------------------------------------------------------
Rectangle* leftBorder = nullptr;
Rectangle* rightBorder = nullptr;
Rectangle* topBorder = nullptr;
Rectangle* bottomBorder = nullptr;

Square* square = nullptr;
Rectangle* rectangle = nullptr;
Circle* circle = nullptr;
Circle* circle2 = nullptr;

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
	CollisionManager::Instance()->Clean();
	PhysicsManager::Instance()->Clean();

	// TESTING DELETE GAME OBJECTS <--------------------------------------------------------------------------------------------------------------------------------------------
	if (leftBorder != nullptr)
	{
		leftBorder->Clean();
		delete leftBorder;
		leftBorder = nullptr;
	}

	if (rightBorder != nullptr)
	{
		rightBorder->Clean();
		delete rightBorder;
		rightBorder = nullptr;
	}

	if (topBorder != nullptr)
	{
		topBorder->Clean();
		delete topBorder;
		topBorder = nullptr;
	}

	if (bottomBorder != nullptr)
	{
		bottomBorder->Clean();
		delete bottomBorder;
		bottomBorder = nullptr;
	}

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

	if (circle2 != nullptr)
	{
		circle2->Clean();
		delete circle2;
		circle2 = nullptr;
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
	leftBorder = new Rectangle(new Parameters(0, 0, true, Color::BLUE, 0), 25, SCREEN_HEIGHT);
	rightBorder = new Rectangle(new Parameters(SCREEN_WIDTH - 25, 0, true, Color::BLUE, 0), 25, SCREEN_HEIGHT);

	topBorder = new Rectangle(new Parameters(0, 0, true, Color::BLUE, 0), SCREEN_WIDTH, 25);
	bottomBorder = new Rectangle(new Parameters(0, SCREEN_HEIGHT - 25, true, Color::BLUE, 0), SCREEN_WIDTH, 25);

	square = new Square(new Parameters(SCREEN_WIDTH * 0.2f, SCREEN_HEIGHT * 0.1f, false, Color::GREEN, 100), 40);
	rectangle = new Rectangle(new Parameters(SCREEN_WIDTH * 0.4f, SCREEN_HEIGHT * 0.1f, false, Color::GREEN, 100), 50, 20);
	circle = new Circle(new Parameters(SCREEN_WIDTH * 0.75f, SCREEN_HEIGHT / 2, false, Color::GREEN, 100), 50);
	circle2 = new Circle(new Parameters(SCREEN_WIDTH * 0.25f, SCREEN_HEIGHT / 2, false, Color::GREEN, 100), 25);

	//AssetManager::Instance()->LoadTexture(leftBorder, renderer);
	//AssetManager::Instance()->LoadTexture(rightBorder, renderer);
	//AssetManager::Instance()->LoadTexture(bottomBorder, renderer);
	//AssetManager::Instance()->LoadTexture(topBorder, renderer);
	//
	//AssetManager::Instance()->LoadTexture(square, renderer);
	//AssetManager::Instance()->LoadTexture(rectangle, renderer);

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
	square->Update(dt);
	rectangle->Update(dt);
	circle->Update(dt);
	circle2->Update(dt);

	CollisionManager::Instance()->CheckCollisions();
}

void Program::Draw()
{
	// INFO: Clear the renderer ready for the next frame to be shown
	SDL_RenderClear(renderer);

	// TEST DRAWING GAME OBJECTS <--------------------------------------------------------------------------------------------------------------------------------------------
	leftBorder->Draw();
	rightBorder->Draw();
	topBorder->Draw();
	bottomBorder->Draw();

	square->Draw();
	rectangle->Draw();
	circle->Draw();
	circle2->Draw();

	// INFO: Present the new frame to the screen
	SDL_RenderPresent(renderer);
}

void Program::DefaultScreenColor()
{
	SDL_SetRenderDrawColor(renderer, screenColor.R, screenColor.G, screenColor.B, screenColor.A);
}
