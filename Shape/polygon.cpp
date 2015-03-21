#include "stdafx.h"

using namespace ShapeLibrary;

Polygon::Polygon(IWindowAPI& _windowAPI)
	:ClosedPolyline(_windowAPI)
{
	windowAPI = &_windowAPI;
}

Polygon::~Polygon()
{

}

void Polygon::draw()
{

}

void Polygon::add(Point& _point)
{
	if (point.size() >= 2)
	{
		if (!validatePoint(_point)) throw runtime_error("Il est impossible d'ajouter un point qui est situé sur l'une des autres lignes du polygone");
	}
	point.push_back(_point);
}

bool Polygon::validatePoint(Point& _point)
{
	if (pointIsOnPreviousLine(_point)) return false;

	if (pointCrossPreviousLine(_point)) return false;

	return true;
}

bool Polygon::pointIsOnPreviousLine(Point& _point)
{
	float left, right, top, bottom;

	for (unsigned int i = 0; i < point.size() - 1; i++)
	{
		float x1 = static_cast<float>(point.at(i).x);
		float x2 = static_cast<float>(point.at(i + 1).x);
		float y1 = static_cast<float>(point.at(i).y);
		float y2 = static_cast<float>(point.at(i + 1).y);
		float px = static_cast<float>(_point.x);
		float py = static_cast<float>(_point.y);

		slope = (y2 - y1) / (x2 - x1);
		yIntersect = y1 - slope * x1;

		if (x1 < x2)
		{
			left = x1;
			right = x2;
		}
		else
		{
			left = x2;
			right = x1;
		}

		if (y1 < y2)
		{
			top = y1;
			bottom = y2;
		}
		else
		{
			top = y1;
			bottom = y2;
		}

		if (slope * px + yIntersect > (py - 0.01) && slope * px + yIntersect < (py + 0.01))
		{
			if (px >= left && px <= right && py >= top && py <= bottom) return true;
		}
	}
	return false;
}

bool Polygon::pointCrossPreviousLine(Point& _point)
{
	return false;
}

