#pragma once
#include "stdafx.h"

#include <vector>

using namespace std;

namespace ShapeLibrary
{

	class Shape
	{
	public:
		Shape(IWindowAPI& _windowAPI);
		virtual ~Shape();
		virtual void draw() =0;
	//	void setLineColor(Color& lineColor);
	//	Color getLineColor();
	//	void setFillColor(Color& fillColor);
	//	Color getFillColor();
	//	Point getPoint(int _index);
	//	int getNumberOfPoints();
		void add(Point& _point);

	private:
		IWindowAPI* windowAPI;
		vector<Point> point;
		Color lineColor;
		Color fillColor;
	};
}
