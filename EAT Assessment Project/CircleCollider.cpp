#include "CircleCollider.h"

#include "AssetManager.h"

CircleCollider::CircleCollider(int x, int y, int radius)
{
	UpdateCircleCollider(x, y, radius);
}

void CircleCollider::DrawCollider(Color color)
{
	Point p{ (float)centreX, (float)centreY };
	AssetManager::Instance()->DrawCircle(p, radius, color, false);
}

void CircleCollider::UpdateCircleCollider(int x, int y, int radius)
{
	centreX = x + radius;
	centreY = y + radius;
	this->radius = radius;
}
