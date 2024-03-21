#include "AssetManager.h"

#include "Program.h"

AssetManager* Singleton<AssetManager>::instance = nullptr;

AssetManager::AssetManager()
{
}

void AssetManager::Clean()
{
	// INFO: Clean up the contents of the unordered map
	for (auto i = textureLib.begin(); i != textureLib.end(); i++)
	{
		SDL_DestroyTexture(i->second);
	}

	textureLib.clear();

	// INFO: Clean up the instance
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}

void AssetManager::LoadTexture(Shape& shape)
{
}

void AssetManager::Draw(int key, int x, int y, int width, int height, const double angle)
{
	SDL_Rect destinationRect = { x, y, width, height };

	if (HasTexture(key))
		SDL_RenderCopyEx(Program::Instance()->GetRenderer(), textureLib[key], NULL, &destinationRect, angle, NULL, SDL_FLIP_NONE);
}

void AssetManager::Draw(int key, int x, int y, int radius, const double angle)
{
	if (HasTexture(key))
		//Draw Circle
}

