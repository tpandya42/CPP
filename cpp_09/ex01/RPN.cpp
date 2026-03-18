#include "RPN.hpp"

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

void 	printStack(std::stack<std::string>& _input)
{
	while (!_input.empty())
	{
		_input.pop();
		std::cout << " ";
	}
	std::cout << std::endl;
}

void 	RPN::parseInput(char **argv)
{
	std::stringstream ss;
	std::string token;
	ss << argv;
	while (ss >> token)
	{
		this->_input.push(token);
	}
}

