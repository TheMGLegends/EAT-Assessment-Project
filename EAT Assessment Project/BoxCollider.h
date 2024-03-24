#pragma once

#include "Collider.h"

#include "SDL.h"

class BoxCollider : public Collider
{
private:
	SDL_Rect boxCollider;

public:
	BoxCollider(int x, int y, int width, int height);

	void DrawCollider(Color color = RED) override;
	void UpdateBoxCollider(int x, int y, int width, int height);
};

