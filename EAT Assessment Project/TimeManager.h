#pragma once

#include "Singleton.h"

constexpr auto MILLISECONDS_IN_SECOND = 1000;

class TimeManager : public Singleton<TimeManager>
{
	// INFO: Grants the base class access to the private and protected
	// member variables and methods of the derived class, specifically
	// the constructor
	friend class Singleton<TimeManager>;

private:
	float deltaTime;
	float previousTime;
	float currentTime;

public:
	/// <summary>
	/// Clean up method during program termination
	/// </summary>
	void Clean() override;

	/// <summary>
	/// Calculates the deltaTime in seconds based on the previous 
	/// and current time values
	/// </summary>
	void Tick();

	/// <summary>
	/// The getter for delta time
	/// </summary>
	/// <returns>Returns the delta time</returns>
	inline float DeltaTime() const { return deltaTime; }

private:
	TimeManager();
};

