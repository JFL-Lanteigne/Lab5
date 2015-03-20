#include "stdafx.h"

using namespace ShapeLibrary;

Circle::Circle(IWindowAPI& _windowAPI)
	:Shape(_windowAPI)
{
	windowAPI = &_windowAPI;
}

Circle::~Circle()
{

}

void Circle::draw()
{
	windowAPI->setDrawingColor(lineColor);
	windowAPI->drawCircle(*center, radius);

	windowAPI->setDrawingColor(fillColor);
	windowAPI->fillCircle(*center, radius);
}

void Circle::setCenter(Point& _point)
{
	center = &_point;
}

void Circle::setRadius(int _radius)
{
	radius = _radius;
}

void Circle::add(Point& _point)
{
	throw runtime_error("Il est impossible d'ajouter un point à un rectangle");
}

