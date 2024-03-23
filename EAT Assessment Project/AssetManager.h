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
	std::unordered_map<int, SDL_Texture*> rectLib;

public:
	/// <summary>
	/// Clean up method during program termination
	/// </summary>
	void Clean() override;

	/// <summary>
	/// Used for checking what type of shape is being passed in and based on this
	/// a different loading function will be run
	/// </summary>
	/// <param name="shape">: The game object you want to load a texture for</param>
	/// <param name="renderer">: The SDL renderer</param>
	void LoadTexture(Shape* shape, SDL_Renderer* renderer);

	/// <summary>
	/// Used for drawing a rect
	/// </summary>
	/// <param name="id">: The id of the texture to use to draw the rect with</param>
	/// <param name="x">: The x position of the rect</param>
	/// <param name="y">: The y position of the rect</param>
	/// <param name="width">: The width of the rect</param>
	/// <param name="height">: The height of the rect</param>
	void DrawRect(int id, int x, int y, int width, int height);

	/// <summary>
	/// Used for drawing a circle
	/// </summary>
	/// <param name="centre">: The centre point of the circle</param>
	/// <param name="radius">: The radius of the circle</param>
	/// <param name="color">: The color that the circle will be drawn in</param>
	void DrawCircle(Point centre, int radius, Color color);

private:
	AssetManager();

	/// <summary>
	/// Used for loading squares and rectangles
	/// </summary>
	/// <param name="id">: The id of the texture to load</param>
	/// <param name="width">: The width of the rect</param>
	/// <param name="height">: The height of the rect</param>
	/// <param name="color">: The color values of the object</param>
	/// <param name="renderer">: The SDL renderer</param>
	void LoadRect(int id, int width, int height, Color color, SDL_Renderer* renderer);
};

