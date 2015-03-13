#include "stdafx.h"

using namespace ShapeLibrary;

Shape::Shape(IWindowAPI& _windowAPI)
{
	windowAPI = &_windowAPI;
}

Shape::~Shape()
{

}


