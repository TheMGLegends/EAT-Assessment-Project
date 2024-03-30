#pragma once

#include "Point.h"

#include "iostream"
#include "cmath"

const int DIRECTIONS_COUNT = 4;

/// <summary>
/// Derived from Point class used for vector calculations
/// </summary>
class Vector2 : public Point
{
public:
	// INFO: Generic Vectors

	static const Vector2 UP;
	static const Vector2 DOWN;
	static const Vector2 LEFT;
	static const Vector2 RIGHT;
	static const Vector2 ZERO;

	static const Vector2 TOP_LEFT;
	static const Vector2 TOP_RIGHT;
	static const Vector2 BOTTOM_LEFT;
	static const Vector2 BOTTOM_RIGHT;

private:
	static const Vector2 DIRECTIONS[DIRECTIONS_COUNT];

public:
	inline Vector2(float x = 0, float y = 0) : Point{ x,y } {}


	// INFO: Calculation Methods

	/// <summary>
	/// Changes the value of the current vector
	/// </summary>
	/// <param name="v">: The vector to be normalized</param>
	/// <returns>Returns a reference to the changed vector</returns>
	static Vector2& Normalize(Vector2& v);

	/// <summary>
	/// Calculates dot product of 2 vectors
	/// </summary>
	/// <param name="v1">: Vector 1</param>
	/// <param name="v2">: Vector 2</param>
	/// <returns>Returns the dot product of the two vectors</returns>
	static float Dot(Vector2 v1, Vector2 v2);

	/// <summary>
	/// Calculates distance between 2 vectors
	/// </summary>
	/// <param name="a">: Vector A</param>
	/// <param name="b">: Vector B</param>
	/// <returns>Returns the distance between vector A and B</returns>
	static float Distance(Vector2 a, Vector2 b);
	
	/// <summary>
	/// Calculates the length of the vector that calls this method
	/// </summary>
	/// <returns>Returns the length of the vector</returns>
	float Magnitude();

	/// <summary>
	/// Calculates the normalized version of the vector from which this 
	/// method was called from whilst retaining the original values
	/// </summary>
	/// <returns>Returns a new normalized vector</returns>
	Vector2 normalized() const;

	/// <summary>
	/// Generates a random direction vector from an array of pre-defined directions
	/// </summary>
	/// <returns>A directional unit vector</returns>
	static Vector2 RandomDirection();


	// INFO: Overloaded Operators

	inline Vector2 operator+(const Vector2& p) const { return Vector2(X + p.X, Y + p.Y); }
	inline Vector2 operator-(const Vector2& p) const { return Vector2(X - p.X, Y - p.Y); }

	inline Vector2 operator/(const Vector2& p) const { return Vector2(X / p.X, Y / p.Y); }
	inline Vector2 operator/(const float s) const { return Vector2(X / s, Y / s); }

	inline Vector2 operator*(const Vector2& p) const { return Vector2(X * p.X, Y * p.Y); }
	inline Vector2 operator*(const float s) const { return Vector2(X * s, Y * s); }

	Vector2& operator+=(const Vector2& p);
	Vector2& operator+=(const float s);

	Vector2& operator-=(const Vector2& p);
	Vector2& operator-=(const float s);

	Vector2& operator/=(const Vector2& p);
	Vector2& operator/=(const float s);

	Vector2& operator*=(const Vector2& p);
	Vector2& operator*=(const float s);

	Vector2& operator=(const Vector2& p);

	inline bool operator==(const Vector2& p) const { return (X == p.X) && (Y == p.Y); }
	inline bool operator!=(const Vector2& p) const { return (X != p.X) || (Y != p.Y); }


	/// <summary>
	/// Displays the x and y coordinates onto the console output window
	/// </summary>
	inline void DisplayXY() override { std::cout << "Vector (" << X << ", " << Y << ")" << std::endl; }
};

