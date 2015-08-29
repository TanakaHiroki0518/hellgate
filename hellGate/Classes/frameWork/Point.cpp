/*
 * Point.cpp
 * 2015/08/22 tanaka.h
 */
#include "Point.h"

const Point Point::ZERO = Point(0.0f, 0.0f);

// コンストラクタ
Point::Point()
: x(0.0f)
, y(0.0f)
{
}

Point::Point(float xx, float yy)
: x(xx)
, y(yy)
{
}

Point::Point(const Point& copy)
{
	x = copy.x;
	y = copy.y;
}

// operator
bool Point::operator==(Point point)
{
	return (x == point.x && y == point.y);
}

bool Point::operator!=(Point point)
{
	return (x != point.x || y != point.y);
}

bool Point::isZero()
{
	return (x == 0.0f && y == 0.0f);
}
