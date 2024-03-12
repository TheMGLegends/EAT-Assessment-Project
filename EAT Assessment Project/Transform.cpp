#include "Transform.h"

#include <cmath>

Transform::Transform(float x, float y) : Point{ x, y }
{
	zRotation = 0.0f;
}

/// <summary>
/// Rotates the object around its local space and z-axis
/// </summary>
/// <param name="zAngle">: Rotation Amount</param>
void Transform::Rotate(float zAngle)
{
	zRotation += zAngle;
}

/// <summary>
/// Returns the up vector based on the objects z-rotation
/// </summary>
/// <returns></returns>
Vector2 Transform::Up()
{
	// INFO: Convert Degrees to Radians since cmath trig uses radians
	double radians = DegToRad(zRotation);

	// INFO: Returns a new vector2 representing the up direction of the object
	return Vector2(std::sin(radians), std::cos(radians));
}

/// <summary>
/// Returns the right vector based on the objects z-rotation
/// </summary>
/// <returns></returns>
Vector2 Transform::Right()
{
	// INFO: Convert Degrees to Radians since cmath trig uses radians
	double radians = DegToRad(zRotation);

	// INFO: Returns a new vector2 representing the right direction of the object
	return Vector2(std::cos(radians), -std::sin(radians));
}
