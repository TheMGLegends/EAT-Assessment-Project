#pragma once

#include "Point.h"

#include "Vector2.h"

// INFO: Global Constants
const float PI = 3.14f;

/// <summary>
/// Derived from Point class used to manipulate the position, orientation and size of objects
/// </summary>
class Transform : public Point
{
private:
	float zRotation;

public:
	Transform(float x = 0, float y = 0);

	// INFO: Translation Methods
	inline void Translate(Vector2 v) { X += v.X; Y += v.Y; }
	inline void TranslateX(float x) { X += x; }
	inline void TranslateY(float y) { Y += y; }

	// INFO: Rotation Methods
	void Rotate(float zAngle);
	Vector2 Up();
	Vector2 Right();

	// INFO: Debug Methods
	inline void DisplayXY() const override { std::cout << "Transform Position (" << X << ", " << Y << ")" << std::endl; }

private:
	// INFO: Helper Methods
	inline float DegToRad(float deg) { return deg * PI / 180; }
};

