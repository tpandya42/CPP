#include "Fixed.hpp"

// DEFAULT CONSTRUCTOR
Fixed::Fixed() : _fixedPointNumber(0)
{
	std::cout << "Default Constructor called" << std::endl;
}

// COPY CONSTRUCTOR ( Initializes a new object as a copy of 'other' )
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy Constructor called" << std::endl;
	this->_fixedPointNumber = other.getRawBits();
}

// INT CONSTRUCTOR
Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointNumber = n << _fractionalBits;
}

// FLOAT CONSTRUCTOR
Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointNumber = roundf(n * (1 << _fractionalBits));
}

// Copy Assignment Operator ( Overwrites an EXISTING object with the value of 'other' )
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other){
		this->_fixedPointNumber = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed(){
	std::cout << "Destructor Called" << std::endl;
}

int	Fixed::getRawBits(void) const 
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointNumber;
}

void	Fixed::setRawBits(int const  bit)
{
	this->_fixedPointNumber = bit;
}

float	Fixed::toFloat(void) const
{
	return (float)this->_fixedPointNumber / (1 << _fractionalBits);
}

int	Fixed::toInt(void) const
{
	return this->_fixedPointNumber / _fractionalBits;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}

