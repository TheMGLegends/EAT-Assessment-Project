#include "Vector2.h"

#include "MemoryLeakDetector.h"

const Vector2 Vector2::UP(0, 1);
const Vector2 Vector2::DOWN(0, -1);
const Vector2 Vector2::LEFT(-1, 0);
const Vector2 Vector2::RIGHT(1, 0);
const Vector2 Vector2::ZERO(0, 0);

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

float Vector2::Dot(Vector2 v1, Vector2 v2)
{
	return (v1.X * v2.X) + (v1.Y * v2.Y);
}

float Vector2::Distance(Vector2 a, Vector2 b)
{
	Vector2 v{ a.X - b.X, a.Y - b.Y };
	return v.Magnitude();
}

float Vector2::Magnitude()
{
	// INFO: Calculate the Magnitude of the Vector
	float magnitude = float(std::sqrt(std::pow(X, 2) + std::powf(Y, 2)));

	// INFO: Round the Magnitude Based on the Level of Decimal Precision
	magnitude = float(roundf(float(magnitude * std::pow(10, DECIMAL_PRECISION))) / std::pow(10, DECIMAL_PRECISION));

	return magnitude;
}

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
