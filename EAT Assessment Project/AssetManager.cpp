#include "AssetManager.h"

#include "Program.h"
#include "Vector2.h"
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"

#include "MemoryLeakDetector.h"

void AssetManager::DrawRect(int x, int y, int width, int height, Color color)
{
	// INFO: Given that there is no renderer we exit the function
	if (Program::Instance()->GetRenderer() == nullptr)
	{
		std::cout << "Renderer is null" << std::endl;
		return;
	}

	// INFO: Creates a Surface that can be colored on
	SDL_Surface* surface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);

	// INFO: Converts RGBA values into pixel values which can then be used
	// to fill in the surface
	Uint32 rectColor = SDL_MapRGBA(surface->format, color.R, color.G, color.B, color.A);

	// INFO: Fills the surface provided with the specified color
	SDL_FillRect(surface, NULL, rectColor);

	// INFO: Converts the surface into a texture
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Program::Instance()->GetRenderer(), surface);

	SDL_FreeSurface(surface);

	SDL_Rect destinationRect{ x, y, width, height };

	// INFO: Draws the texture onto the renderer
	SDL_RenderCopyEx(Program::Instance()->GetRenderer(), texture, NULL, 
					 &destinationRect, 0, NULL, SDL_FLIP_NONE);

	SDL_DestroyTexture(texture);
}

void AssetManager::DrawBoxCollider(int x, int y, int width, int height, Color color)
{
	// INFO: Return if the program isn't in debug mode
	if (!Program::Instance()->IsInDebugMode())
		return;

	SDL_Rect boxCollider{ x, y, width, height };

	SDL_SetRenderDrawColor(Program::Instance()->GetRenderer(), color.R, color.G, color.B, color.A);
	SDL_RenderDrawRect(Program::Instance()->GetRenderer(), &boxCollider);
	Program::Instance()->DefaultScreenColor();
}

void AssetManager::DrawCircle(Transform centre, int radius, Color color, bool isFilled)
{
	// INFO: Given that there is no renderer we exit the function
	if (Program::Instance()->GetRenderer() == nullptr)
	{
		std::cout << "Renderer is null" << std::endl;
		return;
	}

	// INFO: Return if the program isn't in debug mode and isFilled is set to false
	// (Outline is used for debugging purposes)
	if (!Program::Instance()->IsInDebugMode() && !isFilled)
		return;

	// INFO: Set the renderer draw color to the color that is going to represent
	// the circle
	SDL_SetRenderDrawColor(Program::Instance()->GetRenderer(), color.R, color.G,
		color.B, color.A);

	int diameter = radius * 2;

	// INFO: Scans the rect sized area of the circle and detects whether the current
	// point is within the bounds of the circle, if so it will be drawn otherwise
	// it will be ignored
	for (int width = 0; width < diameter; width++)
	{
		for (int height = 0; height < diameter; height++)
		{
			int dx = radius - width; // INFO: Starts far right going all the way left
			int dy = radius - height; // INFO: Starts bottom going all the way up

			Vector2 displacedVector{ (float)dx, (float)dy };

			// INFO: Either fills the entire inside of the circle or only the outline
			// (Outline is used for debugging purposes)
			if (isFilled)
			{
				// INFO: Given that the displaced vector is inside of the circle,
				// a point will be drawn
				if (displacedVector.Magnitude() <= radius)
					SDL_RenderDrawPoint(Program::Instance()->GetRenderer(), (int)(centre.X + dx), (int)(centre.Y + dy));
			}
			else
			{
				// INFO: Given that the displaced vector is on the circumference
				// of the circle a point will be drawn
				if (std::ceil(displacedVector.Magnitude()) == radius)
					SDL_RenderDrawPoint(Program::Instance()->GetRenderer(), (int)(centre.X + dx), (int)(centre.Y + dy));
			}
		}
	}

	// INFO: Set the renderer draw color back to the screen color after having
	// drawn the circle
	Program::Instance()->DefaultScreenColor();
}

