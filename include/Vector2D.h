#ifndef VECTOR_2D_H
#define VECTOR_2D_H

#include <math.h>
#include "Agent.h"

class Vector2D
{
	public:
		Vector2D(int, int);
		~Vector2D();

		int getX() { return x; }
		int getY() { return y; }

		static int distance(int, int, int, int);

	private:
		int x, y;
};

#endif