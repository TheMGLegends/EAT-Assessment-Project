#pragma once

#include "Color.h"

#include <SDL.h>

constexpr auto SCREEN_WIDTH = 960;
constexpr auto SCREEN_HEIGHT = 960;

/// @brief The main class that runs the program
class Program
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	bool isRunning;
	bool inDebugMode;
	Color screenColor;

public:
	// INFO: Delete the Copy Constructor and Assignment Operator, so that 
	// you can't accidentally create more than one instance of the class

	Program(const Program&) = delete;
	void operator=(const Program&) = delete;

	/// @brief Allows access to the singleton by returning it or creating one if one doesn't yet exist
	/// @return A pointer to the instance of the class
	inline static Program* Instance() { return instance != nullptr ? instance : instance = new Program(); }

	/// @brief Cleans up the program by deleting the instance of the program
	void Clean();

	/// <summary>
	/// Initializes the SDL Libraries as well as other things like textures and game objects
	/// </summary>
	/// <param name="WINDOW_TITLE">: The title of the SDL window</param>
	/// <param name="inDebugMode">: Whether the program is in debug mode or not</param>
	/// <param name="screenWidth">: The width of the SDL window</param>
	/// <param name="screenHeight">: The height of the SDL window</param>
	/// <returns>False if it was unable to initialize everything correctly</returns>
	
	/// @brief Initializes the SDL Libraries as well as other things like textures and game objects
	/// @param WINDOW_TITLE : The title of the SDL window
	/// @param inDebugMode : Whether the program is in debug mode or not
	/// @param screenWidth : The width of the SDL window
	/// @param screenHeight : The height of the SDL window
	/// @retval TRUE : If everything was initialized correctly
	/// @retval FALSE : If it was unable to initialize everything correctly
	bool Initialize(const char* WINDOW_TITLE, bool inDebugMode = false, int screenWidth = SCREEN_WIDTH, int screenHeight = SCREEN_HEIGHT);

	/// @brief Handles the users input
	void HandleInput();

	/// @brief Updates all logic associated with each game object that exists in the program
	/// @param dt : The deltaTime value used for scaling things with time
	void Update(float dt);

	/// @brief Calls the draw function of each game object and draws them on the screen
	void Draw();

	/// @brief Getter for whether the program is running
	/// @retval TRUE : If the program is running
	/// @retval FALSE : If the program is not running
	inline bool IsRunning() const { return isRunning; }
	
	/// @brief Setter for whether the program is running
	/// @param isRunning : Whether the program should continue looping
	inline void SetIsRunning(bool isRunning) { this->isRunning = isRunning; }

	/// @brief Getter for whether the program is in debug mode
	/// @retval TRUE : If the program is in debug mode
	/// @retval FALSE : If the program is not in debug mode
	inline bool IsInDebugMode() const { return inDebugMode; }

	/// @brief Setter for whether the program is in debug mode
	/// @param inDebugMode : Whether the program is in debug mode or not
	inline void SetInDebugMode(bool inDebugMode) { this->inDebugMode = inDebugMode; }

	/// @brief Getter for the renderer
	/// @return The renderer
	inline SDL_Renderer* GetRenderer() { return renderer; }

	/// @brief Getter for the screen color
	/// @return The color of the screen
	inline Color GetScreenColor() const { return screenColor; }

	/// @brief Sets the renderer back to the default screen color
	void DefaultScreenColor();

private:
	Program();
	~Program() {}

	static Program* instance;
};

