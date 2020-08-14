#pragma once
#include "Point.h"


class Rectangle
{
private:
	double _length = 0;
	double _width = 0;
	Point _ñenter;

public:
	void SetLength(double length);
	void SetWidth(double width);
	void SetCenter(double xCoordinate, double yCoordinate);
	
	Point GetPoint();
	double GetLength();
	double GetWidth();
	Rectangle(double length, double width, double xCoordinate, double yCoordinate);
	Rectangle() {};
	friend std::wostream& operator<<(std::wostream& os, const Rectangle& rectangle);
};

inline std::wostream& operator<<(std::wostream& os , const Rectangle& rectangle)
{
	return os << rectangle._ñenter 
		<< L" Length = " << std::setw(5) <<rectangle._length
		<< L"; Width = " << std::setw(5) << rectangle._width;
}
void DemoRectangleWithPoint();

