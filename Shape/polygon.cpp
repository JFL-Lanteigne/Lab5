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
	if (point.size() < 3) throw runtime_error("Il doit y avoir au moins 3 points dans un Polygone");

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

void Polygon::add(Point& _point)
{
	if (point.size() >= 2)
	{
		validatePoint(_point);
	}
	point.push_back(_point);
}

bool Polygon::validatePoint(Point& _point)
{
	if (pointIsOnPreviousLine(_point)) throw runtime_error("Il est impossible d'ajouter un point qui est situé sur l'une des autres lignes du polygone");

	if (pointCrossPreviousLine(_point)) throw runtime_error("Il est impossible d'ajouter un point qui ferait croiser les lignes du polygone");

	return true;
}

bool Polygon::pointIsOnPreviousLine(Point& _point)
{
	float left, right, top, bottom;

	for (unsigned int i = 0; i < point.size() - 1; i++)
	{
		bool slopeUndefined = false;
		float x1 = static_cast<float>(point.at(i).x);
		float x2 = static_cast<float>(point.at(i + 1).x);
		float y1 = static_cast<float>(point.at(i).y);
		float y2 = static_cast<float>(point.at(i + 1).y);
		float px = static_cast<float>(_point.x);
		float py = static_cast<float>(_point.y);

		if (x2 - x1 != 0)
		{
			slope = (y2 - y1) / (x2 - x1);
			yIntercept = y1 - slope * x1;
		}
		else
		{
			slope = NULL;
			slopeUndefined = true;
		}

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
			top = y2;
			bottom = y1;
		}
		else
		{
			top = y1;
			bottom = y2;
		}

		if (slopeUndefined == true)
		{
			if (px > (py - 0.01) && px < (py + 0.01))
			{
				if (px >= left && px <= right && py <= top && py >= bottom) return true;
			}
		}
		else
		{
			if (slope * px + yIntercept >(py - 0.01) && slope * px + yIntercept < (py + 0.01))
			{
				if (px >= left && px <= right && py <= top && py >= bottom) return true;
			}
		}
	}
	return false;
}

bool Polygon::pointCrossPreviousLine(Point& _point)
{
	float slopeToCompare;
	float yIntercept2;
	float intersectionX;
	float intersectionY;
	float left, right, top, bottom;

	for (unsigned int i = point.size() - 1; i > 0; i--)
	{
		bool slopeUndefined = false;
		bool slopeToCompareUndefined = false;
		float x1 = static_cast<float>(point.at(i - 1).x);
		float x2 = static_cast<float>(point.at(i).x);
		float y1 = static_cast<float>(point.at(i - 1).y);
		float y2 = static_cast<float>(point.at(i).y);
		float px = static_cast<float>(point.at(point.size() - 1).x);
		float py = static_cast<float>(point.at(point.size() - 1).y);
		float p2x = static_cast<float>(_point.x);
		float p2y = static_cast<float>(_point.y);

		if (p2x - px != 0)
		{
			slope = (p2y - py) / (p2x - px);
			yIntercept = py - slope * px;
		}
		else
		{
			slope = NULL;
			slopeUndefined = true;
		}
		if (x2 - x1 != 0)
		{
			slopeToCompare = (y2 - y1) / (x2 - x1);
			yIntercept2 = y1 - slopeToCompare * x1;
		}
		else
		{
			slopeToCompare = NULL;
			slopeToCompareUndefined = true;
		}

		if (slope != slopeToCompare)
		{
			if (slopeUndefined == true)
			{
				intersectionX = px;
				intersectionY = slopeToCompare * intersectionX + yIntercept2;
			}
			else if (slopeToCompareUndefined == true)
			{
				intersectionX = x1;
				intersectionY = slope * intersectionX + yIntercept;
			}
			else
			{
				intersectionX = (yIntercept2 - yIntercept) / (slope - slopeToCompare);
				intersectionY = slope * intersectionX + yIntercept;
			}

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
				top = y2;
				bottom = y1;
			}
			else
			{
				top = y1;
				bottom = y2;
			}

			if ((intersectionX + 0.01) >= left && (intersectionX - 0.01) <= right && (intersectionY + 0.01) <= top && (intersectionY - 0.01) >= bottom) return true;
		}
	}
	return false;
}

