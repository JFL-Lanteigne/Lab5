#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class ClosedPolyline : public OpenPolyline
	{
	public:
		ClosedPolyline(IWindowAPI& _windowAPI);
		virtual ~ClosedPolyline();
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