#pragma once

struct Color
{
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
		R = 0;
		G = 255;
		B = 0;
		A = 255;
	}

	Color(int R, int G, int B, int A)
	{
		this->R = R;
		this->G = G;
		this->B = B;
		this->A = A;
	}

	static Color RandomColor();
};