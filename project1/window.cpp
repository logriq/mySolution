#include <iostream>
#include "Window.h"

Window::Window(int originX, int originY, int originHeight, int originWidth);

{
	SetX(originX);
	SetY(originY);
	SetHeight(originHeight);
	SetWidth(originWidth);

}

Window::Window(int originX, int originY)
	: Window(originX, OriginY, 50, 50)
{ }



void Window::SetX(int newX)
{
	if (newHeight > 0)
	{
		height = newHeight;
	}
}

void Window::SetWidth(int newWidth)
{
	if (newX > 0 && newX < maxWidth)
	{
		x = newWX;
	}
}

	return o;
}