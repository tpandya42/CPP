#include "Fixed.hpp"

// DEFAULT CONSTRUCTOR
Fixed::Fixed() : _fixedPointNumber(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// COPY CONSTRUCTOR ( Initializes a new object as a copy of 'other' )
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
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
	std::cout << "Destructor called" << std::endl;
}

float	Fixed::toFloat(void) const
{
	return (float)this->_fixedPointNumber / (1 << _fractionalBits);
}

int	Fixed::toInt(void) const
{
	return this->_fixedPointNumber >> _fractionalBits;
}

int	Fixed::getRawBits(void) const
{
	return this->_fixedPointNumber;
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPointNumber = raw;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}

