#include "Vector2.h"

#include "MemoryLeakDetector.h"

const Vector2 Vector2::UP(0, 1);
const Vector2 Vector2::DOWN(0, -1);
const Vector2 Vector2::LEFT(-1, 0);
const Vector2 Vector2::RIGHT(1, 0);
const Vector2 Vector2::ZERO(0, 0);

/// <summary>
/// Changes the values of the current vector and returns a reference to it
/// </summary>
/// <param name="v">: The vector to be normalized</param>
/// <returns></returns>
Vector2& Vector2::Normalize(Vector2& v)
{
	float magnitude = v.Magnitude();

	// INFO: Prevents Dividing Vector by Zero (Undefined Behaviour)
	if (magnitude != 0.0f)
		v /= magnitude;

	// INFO: Round the Vector Based on the Level of Decimal Precision
	v.X = float(roundf(float(v.X * std::pow(10, DECIMAL_PRECISION))) / std::pow(10, DECIMAL_PRECISION));
	v.Y = float(roundf(float(v.Y * std::pow(10, DECIMAL_PRECISION))) / std::pow(10, DECIMAL_PRECISION));

	return v;
}

/// <summary>
/// Returns the dot product of the two provided vectors
/// </summary>
/// <param name="v1">: Vector 1</param>
/// <param name="v2">: Vector 2</param>
/// <returns></returns>
float Vector2::Dot(Vector2 v1, Vector2 v2)
{
	return (v1.X * v2.X) + (v1.Y * v2.Y);
}

/// <summary>
/// Returns the distance between vector A and B
/// </summary>
/// <param name="a">: Vector A</param>
/// <param name="b">: Vector B</param>
/// <returns></returns>
float Vector2::Distance(Vector2 a, Vector2 b)
{
	Vector2 v{ a.X - b.X, a.Y - b.Y };
	return v.Magnitude();
}

/// <summary>
/// Returns the length of the vector from which this function was called from
/// </summary>
/// <returns></returns>
float Vector2::Magnitude()
{
	// INFO: Calculate the Magnitude of the Vector
	float magnitude = float(std::sqrt(std::pow(X, 2) + std::powf(Y, 2)));

	// INFO: Round the Magnitude Based on the Level of Decimal Precision
	magnitude = float(roundf(float(magnitude * std::pow(10, DECIMAL_PRECISION))) / std::pow(10, DECIMAL_PRECISION));

	return magnitude;
}

/// <summary>
/// Retains the values of the curent vector and returns a new normalized vector
/// </summary>
/// <returns></returns>
Vector2 Vector2::normalized() const
{
	Vector2 v = *this;

	float magnitude = v.Magnitude();

	// INFO: Prevents Dividing Vector by Zero (Undefined Behaviour)
	if (magnitude != 0.0f)
		v /= magnitude;

	// INFO: Round the Vector Based on the Level of Decimal Precision
	v.X = float(roundf(float(v.X * std::pow(10, DECIMAL_PRECISION))) / std::pow(10, DECIMAL_PRECISION));
	v.Y = float(roundf(float(v.Y * std::pow(10, DECIMAL_PRECISION))) / std::pow(10, DECIMAL_PRECISION));
	
	return v;
}
