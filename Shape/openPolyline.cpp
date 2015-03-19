#include "stdafx.h"

using namespace ShapeLibrary;

OpenPolyline::OpenPolyline(IWindowAPI& _windowAPI)
	:Shape(_windowAPI)
{
	windowAPI = &_windowAPI;
}

OpenPolyline::~OpenPolyline()
{

}

void OpenPolyline::draw()
{
	windowAPI->setDrawingColor(lineColor);

	for (unsigned int i = 0; i < point.capacity() - 1; i++)
	{
		windowAPI->drawLine(point.at(i), point.at(i + 1));
	}
}

void OpenPolyline::add(Point& _point)
{
	point.push_back(_point);
}