#pragma once

const float MILLISECONDS_IN_SECOND = 1000.0f;

/// @brief Defines the class responsible for managing the time
class TimeManager
{
private:
	static float previousTime;
	static float currentTime;
	static float deltaTime;

public:
	/// @brief Initializes the time values
	static void Initialize();

	/// @brief Calculates the delta time in seconds based on the 
	/// previous and current time values
	static void Tick();

	/// @brief The getter for delta time
	/// @return The current delta time
	static inline float DeltaTime() { return deltaTime; }

private:
	TimeManager();
};

