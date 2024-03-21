#pragma once

#include "Singleton.h"

#include "SDL.h"
#include "Shape.h"

#include <unordered_map>

class AssetManager : public Singleton<AssetManager>
{
	// INFO: Grants the base class access to the private and protected
	// member variables and methods of the derived class, specifically
	// the constructor
	friend class Singleton<AssetManager>;

private:
	std::unordered_map<int, SDL_Texture*> textureLib;

public:
	/// <summary>
	/// Clean up method during program termination
	/// </summary>
	void Clean() override;

	/// <summary>
	/// Loads a default SDL shape texture
	/// </summary>
	/// <param name="shape">: The game object you want to load a texture for</param>
	void LoadTexture(Shape& shape);

	/// <summary>
	/// Used for drawing rects
	/// </summary>
	/// <param name="key">: The key used to access the value in the texture library</param>
	/// <param name="x">: The x-axis value of the objects position</param>
	/// <param name="y">: The y-axis value of the objects position</param>
	/// <param name="width">: The width of the object</param>
	/// <param name="height">: The height of the object</param>
	void Draw(int key, int x, int y, int width, int height, const double angle = 0);

	/// <summary>
	/// Used for drawing circles
	/// </summary>
	/// <param name="key">: The key used to access the value in the texture library</param>
	/// <param name="x">: The x-axis value of the objects position</param>
	/// <param name="y">: The y-axis value of the objects position</param>
	/// <param name="radius">: The radius of object</param>
	void Draw(int key, int x, int y, int radius, const double angle = 0);

private:
	AssetManager();

	inline bool HasTexture(int key) { return textureLib[key] != nullptr; }
};

