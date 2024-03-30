#include "Transform.h"

//#include <cmath>

#include "MemoryLeakDetector.h"

Transform::Transform(float x, float y) :
	Point{ x, y }
{
}

//void Transform::Rotate(float zAngle)
//{
//	zRotation += zAngle;
//}

//Vector2 Transform::Up()
//{
//	// INFO: Convert Degrees to Radians since cmath trig uses radians
//	double radians = DegToRad(zRotation);
//
//	Vector2 v((float)std::sin(radians), (float)std::cos(radians));
//
//	// INFO: Round the Vector Based on the Level of Decimal Precision
//	v.X = float(roundf(float(v.X * std::pow(10, DECIMAL_PRECISION))) / std::pow(10, DECIMAL_PRECISION));
//	v.Y = float(roundf(float(v.Y * std::pow(10, DECIMAL_PRECISION))) / std::pow(10, DECIMAL_PRECISION));
//
//	return v;
//}

//Vector2 Transform::Right()
//{
//	// INFO: Convert Degrees to Radians since cmath trig uses radians
//	double radians = DegToRad(zRotation);
//
//	// INFO: New vector2 representing the right direction of the object
//	Vector2 v((float)std::cos(radians), (float)std::sin(radians));
//
//	// INFO: Round the Vector Based on the Level of Decimal Precision
//	v.X = float(roundf(float(v.X * std::pow(10, DECIMAL_PRECISION))) / std::pow(10, DECIMAL_PRECISION));
//	v.Y = float(roundf(float(v.Y * std::pow(10, DECIMAL_PRECISION))) / std::pow(10, DECIMAL_PRECISION));
//
//	return v;
//}

