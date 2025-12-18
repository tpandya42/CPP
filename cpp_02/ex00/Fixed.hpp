#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

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
		Fixed& operator=(const Fixed& other);
		~Fixed();

		int	getRawBits(void) const;
		void	setRawBits(int const bit);
};


#endif
