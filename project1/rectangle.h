#pragma once
class Rectangle
{
private:
	int height = 10;
	int width = 10;

public:
	void setHeight(int newHeight);
	void setWidth(int newWidth);
	int getHeight() const { return height; }
	int getWidth() { return width; }
};

