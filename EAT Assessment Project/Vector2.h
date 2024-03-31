#pragma once

#include "Point.h"

#include "iostream"
#include "cmath"

const int DIRECTIONS_COUNT = 4;

/// @brief Derived from Point class used for vector calculations
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
	/// @brief Vector2 Constructor
	/// @param x : The x coordinate of the vector
	/// @param y : The y coordinate of the vector
	inline Vector2(float x = 0, float y = 0) : Point{ x,y } {}


	// INFO: Calculation Methods

	/// @brief Changes the value of the current vector
	/// @param v : The vector to be normalized
	/// @return A reference to the changed vector
	static Vector2& Normalize(Vector2& v);

	/// @brief Calculates dot product of 2 vectors
	/// @param v1 : Vector 1
	/// @param v2 : Vector 2
	/// @return The dot product of the two vectors
	static float Dot(Vector2 v1, Vector2 v2);

	/// @brief Calculates the distance between 2 vectors
	/// @param a : Vector A
	/// @param b : Vector B
	/// @return The distance between vector A and B
	static float Distance(Vector2 a, Vector2 b);
	
	/// @brief Calculates the magnitude of the vector
	/// @return The magnitude of the vector
	float Magnitude();

	/// @brief Calculates the normalized version of the vector from which 
	/// this method was called from whilst retaining the original values
	/// @return A new normalized vector
	Vector2 normalized() const;

	/// @brief Generates a random direction vector from an array of pre-defined directions
	/// @return A directional unit vector
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

	
	/// @brief Displays the x and y coordinates onto the console output window
	inline void DisplayXY() override { std::cout << "Vector (" << X << ", " << Y << ")" << std::endl; }
};

