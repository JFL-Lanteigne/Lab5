#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class Polygon : public ClosedPolyline
	{
	public:
		Polygon(IWindowAPI& _windowAPI);
		~Polygon();
		void draw();
		//Point getPoint(int _index);
		//int getNumberOfPoints();
		void add(Point& point);

	private:
		IWindowAPI* windowAPI;
		vector<Point> point;
		float slope;
		float yIntersect;
		Color lineColor;
		Color fillColor;
		bool validatePoint(Point& point);
		bool pointIsOnPreviousLine(Point& point);
		bool pointCrossPreviousLine(Point& point);
	};
}
