#pragma once

#include "Collider.h"

class CircleCollider : public Collider
{
private:
	int* centreX;
	int* centreY;
	int* radius;

public:
	CircleCollider(int &x, int &y, int &radius);
};

