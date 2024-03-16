#include "InputManager.h"

InputManager* Singleton<InputManager>::instance = nullptr;

void InputManager::Clean()
{
	// INFO: Clean up the instance
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}
