#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "<WrongCat> Default constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other)
{
	std::cout << "<WrongCat> Copy constructor is being called" << std::endl;
	this->type = other.type;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "<WrongCat> Copy assignment operator is being called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

WrongCat ::~WrongCat()
{
	std::cout << "<WrongCat> Destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "<WrongCat> Meow Meow!!" << std::endl;
}
