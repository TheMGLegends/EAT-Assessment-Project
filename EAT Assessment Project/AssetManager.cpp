#include "AssetManager.h"

#include "Program.h"

#include "MemoryLeakDetector.h"

AssetManager* Singleton<AssetManager>::instance = nullptr;

AssetManager::AssetManager()
{
}

void AssetManager::LoadRect(int key, int width, int height, Color color, SDL_Renderer* renderer)
{
	SDL_Surface* surface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
	Uint32 rectColor = SDL_MapRGBA(surface->format, color.R, color.G, color.B, color.A);
	SDL_FillRect(surface, NULL, rectColor);

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_FreeSurface(surface);

	rectLib[key] = texture;
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
	switch (shape->GetShapeType())
	{
	case ShapeType::Square:
		break;
	case ShapeType::Rectangle:
		break;
	case ShapeType::Circle:
		break;
	case ShapeType::None:
	default:
		break;
	}
}

//void AssetManager::Draw(int key, int x, int y, int width, int height, const double angle)
//{
//	SDL_Rect destinationRect = { x, y, width, height };
//
//	if (HasTexture(key))
//		SDL_RenderCopyEx(Program::Instance()->GetRenderer(), textureLib[key], NULL, &destinationRect, angle, NULL, SDL_FLIP_NONE);
//}
//
//void AssetManager::Draw(int key, int x, int y, int radius, const double angle)
//{
//	//if (HasTexture(key))
//		//Draw Circle
//}

