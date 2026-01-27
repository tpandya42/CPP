#include "Fixed.hpp"
#include <iostream>

int	main(void)
{
	Fixed	a;
	Fixed const	b(Fixed( 5.05f ) * Fixed (2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;

	Fixed c(2);
	Fixed d(3);

	std::cout << "min(c, d): " << Fixed::min(c, d) << std::endl;
	std::cout << "max(c, d): " << Fixed::max(c, d) << std::endl;

	const Fixed e(10);
	const Fixed f(20);

	std::cout << "min(e, f): " << Fixed::min(e, f) << std::endl;
	std::cout << "max(e, f): " << Fixed::max(e, f) << std::endl;


	return (0);
}
