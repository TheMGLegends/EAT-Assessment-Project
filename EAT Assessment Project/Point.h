#pragma once

#include <iostream>

const int DECIMAL_PRECISION = 2;

/// <summary>
/// Base struct that defines a standard 2D coordinate system
/// </summary>
struct Point
{
	float X;
	float Y;

	inline Point(float x = 0, float y = 0) : X{ x }, Y{ y } {}


	// INFO: Debug Methods

	virtual void DisplayXY() = 0;
};

