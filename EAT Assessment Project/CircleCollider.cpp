#include "CircleCollider.h"

CircleCollider::CircleCollider(int &x, int &y, int &radius)
{
	centreX = &x;
	centreY = &y;
	this->radius = &radius;
}
