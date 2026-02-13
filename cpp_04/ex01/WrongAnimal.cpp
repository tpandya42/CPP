#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "<WrongAnimal> Default constructor called" << std::endl;
	this->type = "Just a wrong animal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "<WrongAnimal> Copy constructor is being called" << std::endl;
	this->type = other.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "<WrongAnimal> Copy assignment operator is being called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "<WrongAnimal> Destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "<WrongAnimal> Just a wrong animal making some sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}
