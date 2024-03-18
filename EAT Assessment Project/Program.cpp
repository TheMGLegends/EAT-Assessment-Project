#include "Program.h"

Program::Program() :
	window{ nullptr },
	renderer{ nullptr },
	isRunning{ false }
{
}

/// <summary>
/// Clean up method during program termination
/// </summary>
void Program::Clean()
{
	// INFO: Destroys the SDL renderer & window
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	//IMG_Quit();

	// INFO: Unloads the main SDL Library
	SDL_Quit();

	// INFO: Clean up the instance
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}

/// <summary>
/// Initializes the SDL Libraries as well as other things like textures and game objects
/// </summary>
/// <param name="WINDOW_TITLE">: The title of the SDL window</param>
/// <param name="screenWidth">: The width of the SDL window</param>
/// <param name="screenHeight">: The height of the SDL window</param>
/// <returns></returns>
bool Program::Initialize(const char* WINDOW_TITLE, int screenWidth, int screenHeight)
{
	return false;
}

/// <summary>
/// Handles the users input
/// </summary>
void Program::HandleInput()
{
}

/// <summary>
/// Processes the events that occur during the execution of the program
/// e.g. (Collision Events)
/// </summary>
void Program::ProcessEvents()
{
}

/// <summary>
/// Updates all logic associated with each game object that exists in the program
/// </summary>
/// <param name="dt">: The deltaTime value used for scaling things with time</param>
void Program::Update(float dt)
{
}

/// <summary>
/// Calls the draw function of each game object and draws them on the screen
/// </summary>
void Program::Draw()
{
}

