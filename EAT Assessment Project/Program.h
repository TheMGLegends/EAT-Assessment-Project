#pragma once

#include "Singleton.h"

#include <SDL.h>

constexpr auto SCREEN_WIDTH = 960;
constexpr auto SCREEN_HEIGHT = 960;

class Program : public Singleton<Program>
{
	// INFO: Grants the base class access to the private and protected
	// member variables and methods of the derived class, specifically
	// the constructor
	friend class Singleton<Program>;

private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	bool isRunning;

public:
	/// <summary>
	/// Clean up method during program termination
	/// </summary>
	void Clean() override;

	/// <summary>
	/// Initializes the SDL Libraries as well as other things like textures and game objects
	/// </summary>
	/// <param name="WINDOW_TITLE">: The title of the SDL window</param>
	/// <param name="screenWidth">: The width of the SDL window</param>
	/// <param name="screenHeight">: The height of the SDL window</param>
	/// <returns>Returns false if it was unable to initialize everything correctly</returns>
	bool Initialize(const char* WINDOW_TITLE, int screenWidth = SCREEN_WIDTH, int screenHeight = SCREEN_HEIGHT);

	/// <summary>
	/// Handles the users input
	/// </summary>
	void HandleInput();

	/// <summary>
	/// Processes the events that occur during the execution of the program
	/// e.g. (Collision Events)
	/// </summary>
	void ProcessEvents();

	/// <summary>
	/// Updates all logic associated with each game object that exists in the program
	/// </summary>
	/// <param name="dt">: The deltaTime value used for scaling things with time</param>
	void Update(float dt);

	/// <summary>
	/// Calls the draw function of each game object and draws them on the screen
	/// </summary>
	void Draw();

	/// <summary>
	/// The getter for whether the program is running
	/// </summary>
	/// <returns>Returns the running state of the program</returns>
	inline bool IsRunning() const { return isRunning; }
	
	/// <summary>
	/// The setter for whether the program is running
	/// </summary>
	/// <param name="isRunning">: Whether the loop should continue looping</param>
	inline void SetIsRunning(bool isRunning) { this->isRunning = isRunning; }

	/// <summary>
	/// The getter for the renderer
	/// </summary>
	/// <returns>Returns the renderer member variable held inside of program</returns>
	inline SDL_Renderer* GetRenderer() { return renderer; }

private:
	Program();
};

