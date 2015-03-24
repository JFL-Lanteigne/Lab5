#include "stdafx.h"

using namespace ShapeLibrary;

Shape::Shape(IWindowAPI& _windowAPI)
{
	windowAPI = &_windowAPI;
}

Shape::~Shape()
{

}

void Shape::setLineColor(Color _lineColor)
{
	lineColor = _lineColor;
}

const Color& Shape::getLineColor() const
{
	return lineColor;
}

void Shape::setFillColor(Color _fillColor)
{
	fillColor = _fillColor;
}

const Color& Shape::getFillColor() const
{
	return fillColor;
}

void Shape::add(const Point& _point)
{
	point.push_back(_point);
}

Point Shape::getPoint(int _index)
{
	return point.at(_index);
}

int Shape::getNumberOfPoints()
{
	return point.size();
}


