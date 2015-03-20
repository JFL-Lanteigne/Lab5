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
	if (point.size() < 2) throw runtime_error("Il doit y avoir au moins 2 points dans un OpenPolyline");
	windowAPI->setDrawingColor(lineColor);

	for (unsigned int i = 0; i < point.size() - 1; i++)
	{
		windowAPI->drawLine(point.at(i), point.at(i + 1));
	}
}

void OpenPolyline::add(Point& _point)
{
	point.push_back(_point);
}