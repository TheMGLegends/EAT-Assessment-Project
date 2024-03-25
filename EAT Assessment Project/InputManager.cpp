#include "InputManager.h"

#include "Program.h"

#include <iostream>

#include "MemoryLeakDetector.h"

Uint8* InputManager::previousKeyboardState = nullptr;
const Uint8* InputManager::KEYBOARD_STATE = nullptr;
int InputManager::keyLength = 0;

void InputManager::Initialize()
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

