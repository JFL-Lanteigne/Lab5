#include "stdafx.h"

using namespace ShapeLibrary;

ClosedPolyline::ClosedPolyline(IWindowAPI& _windowAPI)
	:OpenPolyline(_windowAPI)
{
	windowAPI = &_windowAPI;
}

ClosedPolyline::~ClosedPolyline()
{

}

void ClosedPolyline::draw()
{
	if (point.size() < 3) throw runtime_error("Il doit y avoir au moins 3 points dans un ClosedPolyline");

	windowAPI->setDrawingColor(lineColor);

	for (unsigned int i = 0; i < point.size(); i++)
	{
		if (i != (point.size() - 1)) 
		{
			windowAPI->drawLine(point.at(i), point.at(i + 1));
		}
		else
		{
			windowAPI->drawLine(point.at(i), point.at(i - (point.size() - 1)));
		}
	}
}

void ClosedPolyline::add(Point& _point)
{
	point.push_back(_point);
}

