#include "AssetManager.h"

AssetManager* Singleton<AssetManager>::instance = nullptr;

void AssetManager::Clean()
{
	// INFO: Clean up the instance
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}
