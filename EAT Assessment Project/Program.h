#pragma once

#include "Singleton.h"

#include "Color.h"

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
	bool inDebugMode;
	Color screenColor;

public:
	/// <summary>
	/// Clean up method during program termination
	/// </summary>
	void Clean() override;

	/// <summary>
	/// Initializes the SDL Libraries as well as other things like textures and game objects
	/// </summary>
	/// <param name="WINDOW_TITLE">: The title of the SDL window</param>
	/// <param name="inDebugMode">: Whether the program is in debug mode or not</param>
	/// <param name="screenWidth">: The width of the SDL window</param>
	/// <param name="screenHeight">: The height of the SDL window</param>
	/// <returns>False if it was unable to initialize everything correctly</returns>
	bool Initialize(const char* WINDOW_TITLE, bool inDebugMode = false, int screenWidth = SCREEN_WIDTH, int screenHeight = SCREEN_HEIGHT);

	/// <summary>
	/// Handles the users input
	/// </summary>
	void HandleInput();

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
	/// <returns>The running state of the program</returns>
	inline bool IsRunning() const { return isRunning; }
	
	/// <summary>
	/// The setter for whether the program is running
	/// </summary>
	/// <param name="isRunning">: Whether the program should continue looping</param>
	inline void SetIsRunning(bool isRunning) { this->isRunning = isRunning; }

	/// <summary>
	/// The getter for whether the program is in debug mode
	/// </summary>
	/// <returns>The debug state of the program</returns>
	inline bool IsInDebugMode() const { return inDebugMode; }

	/// <summary>
	/// The setter for whether the program is in debug mode
	/// </summary>
	/// <param name="inDebugMode">: Whether the program is in debug mode or not</param>
	inline void SetInDebugMode(bool inDebugMode) { this->inDebugMode = inDebugMode; }

	/// <summary>
	/// The getter for the renderer
	/// </summary>
	/// <returns>The renderer</returns>
	inline SDL_Renderer* GetRenderer() { return renderer; }

	/// <summary>
	/// The getter for the screen color
	/// </summary>
	/// <returns>The color of the screen</returns>
	inline Color GetScreenColor() const { return screenColor; }

	/// <summary>
	/// Sets the renderer back to the default screen color
	/// </summary>
	void DefaultScreenColor();

private:
	Program();
};

