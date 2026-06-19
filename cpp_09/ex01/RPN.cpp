#include "RPN.hpp"
#include <cctype>
#include <cstdlib>
#include <sstream>
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


void 	RPN::parseInput(const std::string &str)
{
	std::stringstream ss(str);
	std::string token;
	int 	n;

	while (std::getline(ss, token, ' '))
	{
		if (token.length() == 1 && std::isdigit(token[0]) || token.length() == 2 && token[0] == '-' && isdigit(token[1]))
		{
			std::stringstream(token) >> n;
			this->_input.push(n);
		}
		else if (token == "+")
			calculateResult(&RPN::_plus);
		else if (token == "-")
			calculateResult(&RPN::_minus);
//		else if (token == "*")
			
	}
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
