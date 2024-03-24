#pragma once

#include "Collider.h"

class BoxCollider : public Collider
{
private:
	int* x;
	int* y;
	int* width;
	int* height;

public:
	BoxCollider(int &x, int &y, int &width, int &height);
};

