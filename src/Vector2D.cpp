#include "Vector2D.h"

Vector2D::Vector2D(int px, int py)
{
	x = px;
	y = py;
}

Vector2D::~Vector2D()
{
	
}

int Vector2D::distance(int ax, int ay, int bx, int by)
{
	return abs((ax - bx) + (ay - by));
}