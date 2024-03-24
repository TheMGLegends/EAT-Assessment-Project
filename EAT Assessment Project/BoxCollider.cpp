#include "BoxCollider.h"

BoxCollider::BoxCollider(int &x, int &y, int &width, int &height)
{
	this->x = &x;
	this->y = &y;
	this->width = &width;
	this->height = &height;
}
