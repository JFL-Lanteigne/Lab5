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
		void setLineColor(Color _lineColor);
		const Color& getLineColor() const;
		void setFillColor(Color _fillColor);
		const Color& getFillColor() const;
	//	Point getPoint(int _index);
	//	int getNumberOfPoints();
		virtual void add(Point& _point);

	private:
		IWindowAPI* windowAPI;
		vector<Point> point;
		Color lineColor;
		Color fillColor;
	};
}
