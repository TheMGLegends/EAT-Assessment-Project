#pragma once

#include "Transform.h"
#include "Color.h"

#include "SDL.h"

/// @brief Defines the class responsible for managing the assets within the application
class AssetManager
{
public:
	/// @brief Used for drawing a rect
	/// @param x : The x position of the rect
	/// @param y : The y position of the rect
	/// @param width : The width of the rect
	/// @param height : The height of the rect
	/// @param color : The color of the rect
	static void DrawRect(int x, int y, int width, int height, Color color);

	/// @brief Used for drawing the outline for a box collider
	/// @param x : The colliders' x-value
	/// @param y : The colliders' y-value
	/// @param width : The colliders' width
	/// @param height : The colliders' height
	/// @param color : The outline color
	static void DrawBoxCollider(int x, int y, int width, int height, Color color = Color::RED);

	/// @brief Used for drawing a circle as well as the outline for the circle collider
	/// @param centre : The centre point of the circle
	/// @param radius : The radius of the circle
	/// @param color : The color that the circle will be drawn in
	/// @param isFilled : Whether the shape should be colored in or outlined
	static void DrawCircle(Transform centre, int radius, Color color, bool isFilled = true);

private:
	AssetManager();
};

