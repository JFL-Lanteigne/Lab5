#include "stdafx.h"

using namespace ShapeLibrary;

Shape::Shape(IWindowAPI& _windowAPI)
{
	windowAPI = &_windowAPI;
}

Shape::~Shape()
{

}

void Shape::add(Point& _point)
{
	point.push_back(_point);
}


