#include "Rectangle.h"
void Rectangle::setHeight(int newHeight)
{
    if (newHeight > 0)
    {
        height = newHeight;
    }
}
void Rectangle::setWidth(int newWidth)
{
    if (newWidth > 0)
    {
        width = newWidth;
    }
}