#include "stdafx.h"

using namespace ShapeLibrary;

Rectangle::Rectangle(IWindowAPI& _windowAPI)
	:Shape(_windowAPI)
{
	windowAPI = &_windowAPI;
}

Rectangle::~Rectangle()
{

}

void Rectangle::draw()
{
	if (positionSet == false) throw runtime_error("La position n'a pas �t� initialis�e");

	windowAPI->setDrawingColor(fillColor);
	windowAPI->fillRectangle(*position, width, height);

	windowAPI->setDrawingColor(lineColor);
	windowAPI->drawRectangle(*position, width, height);
}

void Rectangle::setPosition(Point& _point)
{
	position = &_point;
	positionSet = true;
}

void Rectangle::setHeight(int _height)
{
	if (_height < 0) throw invalid_argument("La hauteur ne peut pas �tre n�gative");
	height = _height;
}

void Rectangle::setWidth(int _width)
{
	if (_width < 0) throw invalid_argument("La largeur ne peut pas �tre n�gative");
	width = _width;
}

void Rectangle::add(Point& _point)
{
	throw runtime_error("Il est impossible d'ajouter un point � un rectangle");
}


