#pragma once

#include "Point.h"

#include "cmath"

/// <summary>
/// Derived from Point class used for physics purposes like velocities, forces and directions
/// </summary>
class Vector2 : public Point
{
public:
	static const Vector2 UP;
	static const Vector2 DOWN;
	static const Vector2 LEFT;
	static const Vector2 RIGHT;
	static const Vector2 ZERO;

public:
	inline Vector2(float x = 0, float y = 0) : Point{ x,y } {}

	// INFO: Calculation Methods
	static Vector2& Normalize(Vector2& v);
	static float Dot(Vector2 v1, Vector2 v2);
	static float Distance(Vector2 a, Vector2 b);
	
	float Magnitude();
	Vector2 normalized() const;

	// INFO: Debug Methods
	inline void DisplayXY() const override { std::cout << "Vector (" << X << ", " << Y << ")" << std::endl; }
};

