#pragma once

#include <stdlib.h>

/// <summary>
/// Struct that defines RGBA values
/// </summary>
struct Color
{
	// INFO: Generic Colors

	static const Color RED;
	static const Color GREEN;
	static const Color BLUE;
	static const Color WHITE;
	static const Color BLACK;

	int R;
	int G;
	int B;
	int A;

	Color() {
		// INFO: Default is Green
		R = GREEN.R;
		G = GREEN.G;
		B = GREEN.B;
		A = GREEN.A;
	}

	Color(int R, int G, int B, int A)
	{
		this->R = R;
		this->G = G;
		this->B = B;
		this->A = A;
	}

	/// <summary>
	/// Generates a random color with 255 alpha
	/// </summary>
	/// <returns>The randomly generated fully opaque color</returns>
	inline static Color RandomColor() { return Color(rand() % 256, rand() % 256, rand() % 256, 255); }
};

