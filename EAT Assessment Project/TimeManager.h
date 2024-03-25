#pragma once

constexpr auto MILLISECONDS_IN_SECOND = 1000;

class TimeManager
{
private:
	static float deltaTime;
	static float previousTime;
	static float currentTime;

public:
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

