#pragma once

const int DECIMAL_PRECISION = 2;

/// @brief Base struct that defines a standard 2D coordinate system
struct Point
{
	float X;
	float Y;

	/// @brief Point Constructor
	/// @param x : The x coordinate
	/// @param y : The y coordinate
	inline Point(float x = 0, float y = 0) : X{ x }, Y{ y } {}

	/// @brief Displays the x and y coordinates onto the console output window
	virtual void DisplayXY() = 0;
};

