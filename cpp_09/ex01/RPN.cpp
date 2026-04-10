#include "RPN.hpp"
#include <cstdlib>
#include <stdexcept>
#include <string>
#include <vector>

RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(const RPN& other)
{
	*this = other;
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		this->_input = other._input;
	}
	return (*this);
}


void 	RPN::parseInput(char **argv)
{
	std::stringstream ss;
	std::string token;
}

double RPN::_plus(double a, double b)
{
	return (a + b);
}

double RPN::_minus(double a, double b)
{
	return (a - b);
}

double RPN::_multiply(double a, double b)
{
	return (a * b);
}


double RPN::_divide(double a, double b)
{
	if (a == 0)
		throw std::runtime_error("Division with Zero");
	return (a / b);
}
