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
		/*void setLineColor(Color& lineColor);
		Color getLineColor();
		void setFillColor(Color& fillColor);
		Color getFillColor();
		Point getPoint(int _index);
		int getNumberOfPoints();*/
		void add(Point& point);

	private:
		IWindowAPI* windowAPI;
		vector<Point> point;
		Color lineColor;
		Color fillColor;
	};
}
