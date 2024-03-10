#include "Point.h"

#include "MemoryLeakDetector.h"

Point& Point::operator+=(const Point& p)
{
	X += p.X;
	Y += p.Y;
	return *this;
}

Point& Point::operator-=(const Point& p)
{
	X -= p.X;
	Y -= p.Y;
	return *this;
}

Point& Point::operator/=(const Point& p)
{
	X /= p.X;
	Y /= p.Y;
	return *this;
}

Point& Point::operator*=(const Point& p)
{
	X *= p.X;
	Y *= p.Y;
	return *this;
}

Point& Point::operator=(const Point& p)
{
	// INFO: Prevents Self-Assignment
	if (this != &p)
	{
		X = p.X;
		Y = p.Y;
	}

	return *this;
}
