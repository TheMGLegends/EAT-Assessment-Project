#include "AssetManager.h"

#include "Program.h"
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Vector2.h"

#include "MemoryLeakDetector.h"

AssetManager* Singleton<AssetManager>::instance = nullptr;

AssetManager::AssetManager()
{
}


void AssetManager::Clean()
{
	// INFO: Clean up the contents of the unordered rect map
	for (auto i = rectLib.begin(); i != rectLib.end(); i++)
	{
		SDL_DestroyTexture(i->second);
	}

	rectLib.clear();

	// INFO: Clean up the instance
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}

void AssetManager::LoadTexture(Shape* shape, SDL_Renderer* renderer)
{
	// INFO: Based on the Type of Shape we will downcast to that 
	// particular derived class, if we succeed then we'll call
	// the relevant load texture functions for that specific shape
	switch (shape->GetShapeType())
	{
	case ShapeType::Square:
	{
		Square* square = dynamic_cast<Square*>(shape);

		if (square != nullptr)
			LoadRect(square->GetID(), square->GetSize(),
				square->GetSize(), square->GetColor(), renderer);
		else
			std::cout << "Failed downcast to square!" << std::endl;
	}
		break;
	case ShapeType::Rectangle:
	{
		Rectangle* rectangle = dynamic_cast<Rectangle*>(shape);

		if (rectangle != nullptr)
			LoadRect(rectangle->GetID(), rectangle->GetWidth(),
				rectangle->GetHeight(), rectangle->GetColor(), renderer);
		else
			std::cout << "Failed downcast to rectangle!" << std::endl;
	}
		break;
	case ShapeType::Circle:
	case ShapeType::None:
	default:
		break;
	}
}

void AssetManager::LoadRect(int id, int width, int height, Color color, SDL_Renderer* renderer)
{
	// INFO: Creates a Surface that can be colored on
	SDL_Surface* surface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);

	// INFO: Converts RGBA values into pixel values which can then be used
	// to fill in the surface
	Uint32 rectColor = SDL_MapRGBA(surface->format, color.R, color.G, color.B, color.A);

	// INFO: Fills the surface provided with the specified color
	SDL_FillRect(surface, NULL, rectColor);

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_FreeSurface(surface);

	rectLib[id] = texture;
}

void AssetManager::DrawRect(int id, int x, int y, int width, int height)
{
	// INFO: Given that there is no renderer or the ID doesn't match a texture
	// we exit out of the function
	if (Program::Instance()->GetRenderer() == nullptr || rectLib[id] == nullptr)
		return;

	SDL_Rect destinationRect{ x, y, width, height };

	SDL_RenderCopyEx(Program::Instance()->GetRenderer(), rectLib[id], NULL, 
					 &destinationRect, 0, NULL, SDL_FLIP_NONE);
}

void AssetManager::DrawCircle(Point centre, int radius, Color color, bool isFilled)
{
	// INFO: Given that there is no renderer or the ID doesn't match a texture
	// we exit out of the function
	if (Program::Instance()->GetRenderer() == nullptr)
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
