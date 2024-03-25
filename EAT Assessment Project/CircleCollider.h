#pragma once

#include "Collider.h"

class CircleCollider : public Collider
{
private:
	float* centreX;
	float* centreY;
	int* radius;

public:
	CircleCollider(float &x, float &y, int &radius);
};

