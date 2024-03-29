#pragma once

const float MILLISECONDS_IN_SECOND = 1000.0f;

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
	/// <returns>Returns the delta time</returns>
	static inline float DeltaTime() { return deltaTime; }

private:
	TimeManager() {}
};

