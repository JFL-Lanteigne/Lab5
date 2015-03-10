#include "stdafx.h"

#include <stdexcept>

using namespace ShapeLibrary;


Point::Point( double _x, double _y ) :
	x(_x), 
	y(_y)
{	
	if (x < 0) throw invalid_argument("x ne doit pas être plus petit que 0");
	if (y < 0) throw invalid_argument("y ne doit pas être plus petit que 0");
}

bool Point::operator == (const Point & point) const
{
	if (x != point.x || y != point.y)
	{
		return false;
	}
	return true;
}

bool Point::operator != (const Point & point) const
{
	if (operator==(point)) return false;
	return true;
}
