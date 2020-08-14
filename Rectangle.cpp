#include <iostream>
#include <vector>
#include <array>
#include <cassert>

#include "CinInputValidation.h"
#include "Rectangle.h"

void Rectangle::SetLength(double length)
{
	assert(length > 0);
	this->_length = length;
}

void Rectangle::SetWidth(double width)
{
	assert(width > 0);
	this->_width = width;
}

void Rectangle::SetCenter(double xCoordinate, double yCoordinate)
{
	this->_сenter =  Point(xCoordinate, yCoordinate);
}

Point Rectangle::GetPoint()
{
	return this->_сenter;
}

double Rectangle::GetLength()
{
	return this->_length;
}

double Rectangle::GetWidth()
{
	return this->_width;
}

Rectangle::Rectangle(double length, double width,
	double xCoordinate, double yCoordinate)
{
	this->SetLength(length);
	this->SetWidth(width);
	this->SetCenter(xCoordinate, yCoordinate);
}

void DemoRectangleWithPoint()
{
	std::vector<Rectangle> rectangles;
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		rectangles.push_back(Rectangle(tools::random(1, 50),
			tools::random(1, 50), tools::random(-20, 20), 
			tools::random(-20, 20)));
	}
	std::copy(rectangles.begin(), rectangles.end(), 
		std::ostream_iterator<Rectangle, wchar_t>(std::wcout, L"\n"));
	
	Point meanCenter(0, 0);
	for (auto i : rectangles)
	{
		meanCenter.SetX(meanCenter.GetX() + i.GetPoint().GetX() / (uint16_t)rectangles.size()) ;
		meanCenter.SetY(meanCenter.GetY() + i.GetPoint().GetY() / (uint16_t)rectangles.size());
	}
	std::wcout << L"\n Среднее значение всех центров: " << meanCenter << std::endl;
}