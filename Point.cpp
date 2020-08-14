#include <iostream>
#include <exception>
#include <cassert>

#include "Point.h"

void Point::SetX(double x)
{
	assert (x > -20.0 || x < 20.0);
	this->_x = x;
}

void Point::SetY(double y)
{
	assert (y > -20.0 || y < 20.0);
	this->_y = y;
}

double Point::GetX()
{
	return this->_x;
}

double Point::GetY()
{
	return this->_y;
}

Point::Point(double x, double y)
{
	this->SetX(x);
	this->SetY(y);
}