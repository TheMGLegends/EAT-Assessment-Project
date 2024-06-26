#pragma once

#include "Point.h"

#include "Vector2.h"

//const float PI = 3.14f;

/// @brief Derived from Point class used to manipulate the position of objects
class Transform : public Point
{
//private:
//	float zRotation;

public:
	/// @brief Transform Constructor
	/// @param x : x-coordinate
	/// @param y : y-coordinate
	Transform(float x = 0, float y = 0);


	// INFO: Translation Methods

	inline void Translate(Vector2 v) { X += v.X; Y += v.Y; }
	inline void TranslateX(float x) { X += x; }
	inline void TranslateY(float y) { Y += y; }


	/*
	// INFO: Rotation Methods

	/// <summary>
	/// Rotates the object around its local space and z-axis
	/// </summary>
	/// <param name="zAngle">: Rotation Amount</param>
	void Rotate(float zAngle);

	/// <summary>
	/// The up vector of the transform
	/// </summary>
	/// <returns>Returns the up vector based on the objects z-rotation</returns>
	Vector2 Up();

	/// <summary>
	/// The right vector of the transform
	/// </summary>
	/// <returns>Returns the right vector based on the objects z-rotation</returns>
	Vector2 Right();
	*/


	/// @brief Displays the x and y coordinates onto the console output window
	inline void DisplayXY() override { std::cout << "Transform Position (" << X << ", " << Y << ")" << std::endl; }

//private:
//	// INFO: Helper Methods
//
//	inline float DegToRad(float deg) { return deg * PI / 180; }
};

