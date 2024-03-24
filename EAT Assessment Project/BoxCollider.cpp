#include "BoxCollider.h"

BoxCollider::BoxCollider(int x, int y, int width, int height)
{
	UpdateBoxCollider(x, y, width, height);
}

void BoxCollider::DrawCollider(Color color)
{
	SDL_SetRenderDrawColor(Program::Instance()->GetRenderer(), color.R, color.G, color.B, color.A);
	SDL_RenderDrawRect(Program::Instance()->GetRenderer(), &boxCollider);
	Program::Instance()->DefaultScreenColor();
}

void BoxCollider::UpdateBoxCollider(int x, int y, int width, int height)
{
	boxCollider.x = x;
	boxCollider.y = y;
	boxCollider.w = width;
	boxCollider.h = height;
}
