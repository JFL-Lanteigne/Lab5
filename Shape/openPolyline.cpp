#include "stdafx.h"

using namespace ShapeLibrary;

OpenPolyline::OpenPolyline(IWindowAPI& _windowAPI)
	:Shape(_windowAPI)
{

}

OpenPolyline::~OpenPolyline()
{

}

void OpenPolyline::draw()
{
	windowAPI->setDrawingColor(lineColor);

	for (int i = 0; i < point.max_size; i++)
	{
		windowAPI->drawLine(point.at(i), point.at(i + 1));
	}
}

void OpenPolyline::add(Point& _point)
{
	point.push_back(_point);
}