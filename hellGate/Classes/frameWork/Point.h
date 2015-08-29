/*
 * Point.h
 * 2015/08/22 tanaka.h
 */
#ifndef __FW_POINT_H__
#define __FW_POINT_H__

#include <iostream>

class Point
{
public:
	float x = 0.0f;
	float y = 0.0f;

	// コンストラクタ
	Point();
	Point(float xx, float yy);
	Point(const Point& copy);

	// operator
	bool operator==(Point point);
	bool operator!=(Point point);

	bool isZero();

	static const Point ZERO;
};

#endif /*__POINT_H__*/
