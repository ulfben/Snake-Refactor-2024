#include "Rectangle.h"

Rectangle::Rectangle() : x(0), y(0), w(0), h(0)
{
}

Rectangle::Rectangle(const Rectangle& rhs) : x(rhs.x), y(rhs.y), w(rhs.w), h(rhs.h)
{
}

Rectangle::Rectangle(int x_, int y_, int w_, int h_) : x(x_), y(y_), w(w_), h(h_)
{
}

void Rectangle::SetBounds(int x_, int y_, int w_, int h_)
{
	this->x = x_; this->y = y_; this->w = w_; this->h = h_;
}
