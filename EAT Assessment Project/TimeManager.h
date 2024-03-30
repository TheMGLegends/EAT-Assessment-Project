#pragma once

const float MILLISECONDS_IN_SECOND = 1000.0f;

/// <summary>
/// Defines the class responsible for managing the time
/// </summary>
class TimeManager
{
private:
	static float previousTime;
	static float currentTime;
	static float deltaTime;

public:
	/// <summary>
	/// Initializes the time values
	/// </summary>
	static void Initialize();

	/// <summary>
	/// Calculates the deltaTime in seconds based on the previous 
	/// and current time values
	/// </summary>
	static void Tick();

	/// <summary>
	/// The getter for delta time
	/// </summary>
	/// <returns>The current delta time</returns>
	static inline float DeltaTime() { return deltaTime; }

private:
	TimeManager();
};

