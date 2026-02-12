#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "<Cat> Default constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat& other)
{
	std::cout << "<Cat> Copy constructor is being called" << std::endl;
	this->type = other.type;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "<Cat> Copy assignment operator is being called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Cat ::~Cat()
{
	std::cout << "<Cat> Destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "<Cat> Meow Meow!!" << std::endl;
}

std::string Cat::getType() const
{
	return (this->type);
}
