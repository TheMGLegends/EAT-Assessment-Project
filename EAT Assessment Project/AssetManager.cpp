#include "AssetManager.h"

#include "Program.h"
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"

#include "MemoryLeakDetector.h"

AssetManager* Singleton<AssetManager>::instance = nullptr;

AssetManager::AssetManager()
{
}

void AssetManager::LoadRect(int id, int width, int height, Color color, SDL_Renderer* renderer)
{
	SDL_Surface* surface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
	Uint32 rectColor = SDL_MapRGBA(surface->format, color.R, color.G, color.B, color.A);
	SDL_FillRect(surface, NULL, rectColor);

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_FreeSurface(surface);

	rectLib[id] = texture;
}

void AssetManager::LoadCircle(int id, Point centre, int radius)
{
	SDL_Point centrePoint{ centre.X, centre.Y };

	std::vector<SDL_Point> points;

	int diameter = radius * 2;

	int x = radius - 1;
	int y = 0;
	int tx = 1;
	int ty = 1;
	int error = tx - diameter;

	while (x >= y)
	{
		points.push_back({ centrePoint.x + x, centrePoint.y - y });
		points.push_back({ centrePoint.x + x, centrePoint.y + y });
		points.push_back({ centrePoint.x - x, centrePoint.y - y });
		points.push_back({ centrePoint.x - x, centrePoint.y + y });
		points.push_back({ centrePoint.x + y, centrePoint.y - x });
		points.push_back({ centrePoint.x + y, centrePoint.y + x });
		points.push_back({ centrePoint.x - y, centrePoint.y - x });
		points.push_back({ centrePoint.x - y, centrePoint.y + x });

		if (error <= 0)
		{
			++y;
			error += ty;
			ty += 2;
		}

		if (error > 0)
		{
			--x;
			tx += 2;
			error += (tx - diameter);
		}
	}

	circleLib[id] = points;
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
	{
		Circle* circle = dynamic_cast<Circle*>(shape);

		if (circle != nullptr)
			LoadCircle(circle->GetID(), circle->GetCentrePoint(), 
				circle->GetRadius());
		else
			std::cout << "Failed downcast to circle!" << std::endl;
	}
		break;
	case ShapeType::None:
		break;
	default:
		break;
	}
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

void AssetManager::DrawCircle(int id, Color color)
{
	// INFO: Given that there is no renderer or the ID doesn't match a texture
	// we exit out of the function
	if (Program::Instance()->GetRenderer() == nullptr || circleLib[id].empty())
		return;

	SDL_SetRenderDrawColor(Program::Instance()->GetRenderer(), color.R, color.G, 
						   color.B, color.A);

	SDL_RenderDrawPoints(Program::Instance()->GetRenderer(), circleLib[id].data(), 
					     circleLib[id].size());

	// INFO: Set the Initial Screen Color (White and Fully Opaque)
	SDL_SetRenderDrawColor(Program::Instance()->GetRenderer(), 255, 255, 255, 255);
}
