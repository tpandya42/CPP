#include "Point.hpp"

Point::Point(void) : x(0), y(0){}
Point::Point(const float val1, const float val2) : x(val1), y(val2){}
Point::Point(const Point& other) : x(other.x), y(other.y){}
Point& Point::operator=(const Point &other)
{
	if (this != &other)
	{
		(Fixed) this->x = other.get_x();
		(Fixed) this->y = other.get_y();
	}
	return *this;
}

Fixed Point::get_x(void)const {
	return this->x;
}

Fixed Point::get_y(void)const {
	return this->y;
}

Point::~Point(){}
