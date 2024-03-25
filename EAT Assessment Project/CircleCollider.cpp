#include "CircleCollider.h"

CircleCollider::CircleCollider(float &x, float &y, int &radius)
{
	centreX = &x;
	centreY = &y;
	this->radius = &radius;
}
