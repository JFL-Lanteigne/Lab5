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
	if (centerSet == false) throw runtime_error("Le centre n'a pas été initialisé");

	windowAPI->setDrawingColor(lineColor);
	windowAPI->drawCircle(*center, radius);

	windowAPI->setDrawingColor(fillColor);
	windowAPI->fillCircle(*center, radius);
}

void Circle::setCenter(Point& _point)
{
	center = &_point;
	centerSet = true;
}

void Circle::setRadius(int _radius)
{
	if (_radius < 0) throw invalid_argument("Le rayon du cercle ne peut pas être négatif");
	radius = _radius;
}

void Circle::add(Point& _point)
{
	throw runtime_error("Il est impossible d'ajouter un point à un cercle");
}

