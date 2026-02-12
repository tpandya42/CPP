#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "<Dog> Default constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog& other)
{
	std::cout << "<Dog> Copy constructor is being called" << std::endl;
	this->type = other.type;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "<Dog> Copy assignment operator is being called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Dog ::~Dog()
{
	std::cout << "<Dog> Destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "<Dog> Woof Woof!!" << std::endl;
}

std::string Dog::getType() const
{
	return (this->type);
}
