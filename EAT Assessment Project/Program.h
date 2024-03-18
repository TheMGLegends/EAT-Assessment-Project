#pragma once

#include "Singleton.h"

#include <SDL.h>

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
	void Clean() override;

	bool Initialize(const char* WINDOW_TITLE, int screenWidth, int screenHeight);
	void HandleInput();
	void ProcessEvents();
	void Update(float dt);
	void Draw();

	inline bool IsRunning() const { return isRunning; }

private:
	Program();
};

