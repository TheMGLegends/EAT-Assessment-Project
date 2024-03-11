#pragma once

#include "Point.h"

#include "Vector2.h"

/// <summary>
/// Derived from Point class used to manipulate the position, orientation and size of objects
/// </summary>
class Transform : public Point
{
private:
	//Transform* up;
	//Transform* down;

public:
	Transform(float x = 0, float y = 0);

	// INFO: Translation Methods
	inline void Translate(Vector2 v) { X += v.X; Y += v.Y; }
	inline void TranslateX(float x) { X += x; }
	inline void TranslateY(float y) { Y += y; }

	inline void DisplayXY() const override { std::cout << "Transform Position (" << X << ", " << Y << ")" << std::endl; }
};

