#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class Circle : public Shape
	{
	public:
		Circle(IWindowAPI& _windowAPI);
		~Circle();
		void draw();
		void add(Point& _point);
		void setCenter(Point& _point);
		void setRadius(int _radius);

	private:
		IWindowAPI* windowAPI;
		Point* center;
		int radius;
		Color lineColor;
		Color fillColor;
		bool centerSet = false;
	};
}
