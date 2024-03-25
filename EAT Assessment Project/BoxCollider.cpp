#include "BoxCollider.h"

BoxCollider::BoxCollider(float &x, float &y, int &width, int &height)
{
	this->x = &x;
	this->y = &y;
	this->width = &width;
	this->height = &height;
}
