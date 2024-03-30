#include "Vector2.h"

#include "MemoryLeakDetector.h"

const Vector2 Vector2::UP(0, 1);
const Vector2 Vector2::DOWN(0, -1);
const Vector2 Vector2::LEFT(-1, 0);
const Vector2 Vector2::RIGHT(1, 0);
const Vector2 Vector2::ZERO(0, 0);

const Vector2 Vector2::TOP_LEFT(-1, 1);
const Vector2 Vector2::TOP_RIGHT(1, 1);
const Vector2 Vector2::BOTTOM_LEFT(-1, -1);
const Vector2 Vector2::BOTTOM_RIGHT(1, -1);

const Vector2 Vector2::DIRECTIONS[DIRECTIONS_COUNT] = {
	TOP_LEFT , TOP_RIGHT, BOTTOM_LEFT, BOTTOM_RIGHT
};

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

Vector2 Vector2::RandomDirection()
{
	// INFO: Random Number between 0 and DIRECTIONS_SIZE - 1
	int randomIndex = rand() % DIRECTIONS_COUNT;
	return DIRECTIONS[randomIndex];
}

Vector2& Vector2::operator+=(const Vector2& p)
{
	X += p.X;
	Y += p.Y;
	return *this;
}

Vector2& Vector2::operator+=(const float s)
{
	X += s;
	Y += s;
	return *this;
}

Vector2& Vector2::operator-=(const Vector2& p)
{
	X -= p.X;
	Y -= p.Y;
	return *this;
}

Vector2& Vector2::operator-=(const float s)
{
	X -= s;
	Y -= s;
	return *this;
}

Vector2& Vector2::operator/=(const Vector2& p)
{
	X /= p.X;
	Y /= p.Y;
	return *this;
}

Vector2& Vector2::operator/=(const float s)
{
	X /= s;
	Y /= s;
	return *this;
}

Vector2& Vector2::operator*=(const Vector2& p)
{
	X *= p.X;
	Y *= p.Y;
	return *this;
}

Vector2& Vector2::operator*=(const float s)
{
	X *= s;
	Y *= s;
	return *this;
}

Vector2& Vector2::operator=(const Vector2& p)
{
	// INFO: Prevents Self-Assignment
	if (this != &p)
	{
		X = p.X;
		Y = p.Y;
	}

	return *this;
}
