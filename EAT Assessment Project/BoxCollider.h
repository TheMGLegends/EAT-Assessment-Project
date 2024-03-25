#pragma once

#include "Collider.h"

class BoxCollider : public Collider
{
private:
	float* x;
	float* y;
	int* width;
	int* height;

public:
	BoxCollider(float &x, float &y, int &width, int &height);
};

