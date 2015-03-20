#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class OpenPolyline : public Shape
	{
	public:
		OpenPolyline(IWindowAPI& _windowAPI);
		virtual ~OpenPolyline();
		virtual void draw();
		//Point getPoint(int _index);
		//int getNumberOfPoints();
		virtual void add(Point& point);

	private:
		IWindowAPI* windowAPI;
		vector<Point> point;
		Color lineColor;
		Color fillColor;
	};
}
