#include "InputManager.h"

#include "Program.h"

#include <iostream>

#include "MemoryLeakDetector.h"

InputManager* Singleton<InputManager>::instance = nullptr;

InputManager::InputManager() : 
	previousKeyboardState{ nullptr }, 
	KEYBOARD_STATE{ nullptr },
	keyLength{ 0 }
{
	// INFO: Get the state of the keyboard
	KEYBOARD_STATE = SDL_GetKeyboardState(&keyLength);

	// INFO: Initialise the previous keyboard state with the
	// size of keyLength
	previousKeyboardState = new Uint8[keyLength];

	// INFO: Copy the contents of KEYBOARD_STATE into previousKeyboardState
	std::memcpy(previousKeyboardState, KEYBOARD_STATE, keyLength);
}

void InputManager::Clean()
{
	// INFO: Clean up the contents of the previous keyboard state
	if (previousKeyboardState != nullptr)
	{
		delete[] previousKeyboardState;
		previousKeyboardState = nullptr;
	}

	// INFO: Clean up the instance
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}

void InputManager::PollEvents()
{
	// INFO: Copy the contents of KEYBOARD_STATE into previousKeyboardState
	// so that events current and previous events can be compared
	std::memcpy(previousKeyboardState, KEYBOARD_STATE, keyLength);

	SDL_Event sdlEvent{};
	while (SDL_PollEvent(&sdlEvent))
	{
		switch (sdlEvent.type)
		{
		case SDL_QUIT:
			Program::Instance()->SetIsRunning(false);
			break;
		default:
			break;
		}
	}
}

