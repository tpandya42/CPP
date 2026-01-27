#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

void	point_in(const Point &a, const Point &b, const Point &c,
		const Point &point)
{
	if (bsp(a, b, c, point))
		std::cout << " Point is inside the triangle" << std::endl;
	else
		std::cout << "No it is not " << std::endl;
}

int	main(void)
{
	Point A(3, 4);
	Point B(8, 4);
	Point C(2, -2);
	Point D(float(4), float(3));
	Point F(float(4), float(4));
	Point E(float(4.0183),
			float(3.9));
	Point G(float(4.00389),
			float(4.4035));                  
	Point H(float(-4.00389), float(-4.4035));
	Point I(float(2), float(-2));            
	point_in(A, B, C, D);
	point_in(A, B, C, F);             
	point_in(A, B, C, E);             
	point_in(A, B, C, G);             
	point_in(A, B, C, H);             
	return (0);
}
