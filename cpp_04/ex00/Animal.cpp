#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "<Animal> Default constructor called" << std::endl;
	this->type = "Just an animal";
}

Animal::Animal(const Animal& other)
{
	std::cout << "<Animal> Copy constructor is being called" << std::endl;
	this->type = other.type;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "<Animal> Copy assignment operator is being called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "<Animal> Destructor called" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "<Animal> Just an animal making some sound" << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}
