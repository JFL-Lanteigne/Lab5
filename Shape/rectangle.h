#pragma once
#include "stdafx.h"

namespace ShapeLibrary 
{
	class Rectangle : public Shape
	{
	public:
		Rectangle(IWindowAPI& _windowAPI);
		~Rectangle();
		void draw();
		void add(Point& _point);
		void setPosition(Point& _point);
		void setHeight(int _height);
		void setWidth(int _width);

	private:
		IWindowAPI* windowAPI;
		Point* position;
		int height;
		int width;
		Color lineColor;
		Color fillColor;
		bool positionSet = false;
	};
}