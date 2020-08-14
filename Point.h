#pragma once
#include <iostream>
#include <iomanip>

class Point
{
private:
	double _x = 0;
	double _y= 0;

public:
	void SetX(double x);
	void SetY(double y);

	double GetX();
	double GetY();

	Point(double x, double y);
	Point() {}
	friend std::wostream& operator<<(std::wostream& os, const Point& point);
};

inline std::wostream& operator<<(std::wostream& os, const Point& point)
{
	os.precision(3);
	return os << L"X = " << std::setw(7) << point._x 
		<< L"; Y = " << std::setw(7) << point._y << L";";
}