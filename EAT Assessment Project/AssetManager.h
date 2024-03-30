#pragma once

#include "Transform.h"
#include "Color.h"

#include "SDL.h"

/// <summary>
/// Defines the class responsible for managing the assets within the application
/// </summary>
class AssetManager
{
public:
	/// <summary>
	/// Used for drawing a rect
	/// </summary>
	/// <param name="x">: The x position of the rect</param>
	/// <param name="y">: The y position of the rect</param>
	/// <param name="width">: The width of the rect</param>
	/// <param name="height">: The height of the rect</param>
	static void DrawRect(int x, int y, int width, int height, Color color);

	/// <summary>
	/// Used for drawing the outline for a box collider
	/// </summary>
	/// <param name="x">: The colliders' x-value</param>
	/// <param name="y">: The colliders' y-value</param>
	/// <param name="width">: The colliders' width</param>
	/// <param name="height">: The colliders' height</param>
	/// <param name="color">: The outline color</param>
	static void DrawBoxCollider(int x, int y, int width, int height, Color color = Color::RED);

	/// <summary>
	/// Used for drawing a circle as well as the outline for the circle collider
	/// </summary>
	/// <param name="centre">: The centre point of the circle</param>
	/// <param name="radius">: The radius of the circle</param>
	/// <param name="color">: The color that the circle will be drawn in</param>
	/// <param name="isFilled">: Whether the shape should be colored in or outlined</param>
	static void DrawCircle(Transform centre, int radius, Color color, bool isFilled = true);

private:
	AssetManager();
};

