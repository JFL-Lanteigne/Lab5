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
	windowAPI->setDrawingColor(lineColor);

	windowAPI->drawRectangle(*position, width, height);
}

void Rectangle::setPosition(Point& _point)
{
	position = &_point;
}

void Rectangle::setHeight(int _height)
{
	height = _height;
}

void Rectangle::setWidth(int _width)
{
	width = _width;
}

void Rectangle::add(Point& _point)
{
	throw runtime_error("Il est impossible d'ajouter un point à un rectangle");
}


