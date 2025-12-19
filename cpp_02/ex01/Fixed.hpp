#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

/*
 * COPY CONSTRUCTOR : It takes reference to another object of same class
 * 		      We use const because we basically copy from 'other'...
 *
 * ASSIGNMENT OPERATOR : 'operator' -> special function name.. it tells that whenever you see the'=' sign between two objects of same class., the run this funciton
 *
 * 		-> It returns a reference to the object itself (*this)....
 * 		-> a=b=c... b=c happens first which returns b, then a =b..
 * 		*/

class Fixed {
	private:
		int _fixedPointNumber;
		static const int _fractionalBits = 8;
	
	public:
		Fixed();
		Fixed(const Fixed& other);	
		// CONSTRUCTOR: int -> fixed point	
		Fixed(const int n);
		// CONSTRUCTOR: float -> fixed point
		Fixed(const float n);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		// fixed point -> float
		float toFloat(void) const;
		// fixed point -> int
		int toInt(void) const;

		int getRawBits(void) const;
		void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
