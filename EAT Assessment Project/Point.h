#pragma once

#include <iostream>

// INFO: Global Constants
const int DECIMAL_PRECISION = 2;

/// <summary>
/// Base class that defines a standard 2D coordinate system
/// </summary>
class Point
{
public:
	float X;
	float Y;

public:
	inline Point(float x = 0, float y = 0) : X{ x }, Y{ y } {}

	// INFO: Overloaded Operators
	inline Point operator+(const Point& p) const { return Point(X + p.X, Y + p.Y); }
	inline Point operator-(const Point& p) const { return Point(X - p.X, Y - p.Y); }

	inline Point operator/(const Point& p) const { return Point(X / p.X, Y / p.Y); }
	inline Point operator/(const float s) const { return Point(X / s, Y / s); }

	inline Point operator*(const Point& p) const { return Point(X * p.X, Y * p.Y); }
	inline Point operator*(const float s) const { return Point(X * s, Y * s); }

	Point& operator+=(const Point& p);
	Point& operator+=(const float s);

	Point& operator-=(const Point& p);
	Point& operator-=(const float s);

	Point& operator/=(const Point& p);
	Point& operator/=(const float s);

	Point& operator*=(const Point& p);
	Point& operator*=(const float s);

	Point& operator=(const Point& p);

	inline bool operator==(const Point& p) const { return (X == p.X) && (Y == p.Y); }
	inline bool operator!=(const Point& p) const { return (X != p.X) || (Y != p.Y); }

	// INFO: Debug Methods
	inline virtual void DisplayXY() const { std::cout << "Location (" << X << ", " << Y << ")" << std::endl; }
};

