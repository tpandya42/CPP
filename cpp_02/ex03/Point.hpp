#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <cmath>
class Point {
	private:
		const Fixed x;
		const Fixed y;

	public:
		Point();
		Point(const float val1, const float val2);
		Point(const Point& other);
		Point& operator=(const Point& other);
		~Point();

		Fixed get_x(void) const;
		Fixed get_y(void) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
