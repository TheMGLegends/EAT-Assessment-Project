#pragma once

#include "Singleton.h"

#include <SDL.h>

class InputManager : public Singleton<InputManager>
{
	// INFO: Grants the base class access to the private and protected
	// member variables and methods of the derived class, specifically
	// the constructor
	friend class Singleton<InputManager>;

private:
	Uint8* previousKeyboardState;
	const Uint8* KEYBOARD_STATE;
	int keyLength;

public:
	void Clean() override;
	void PollEvents();

	// INFO: Returns true when the key is first pressed down
	inline bool GetKeyDown(SDL_Keycode key) { return !previousKeyboardState[key] && KEYBOARD_STATE[key]; }

private:
	InputManager();
};

