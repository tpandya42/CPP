#include "RPN.hpp"
#include <cctype>
#include <cstdlib>
#include <sstream>
#include <stdexcept>
#include <string>

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& other) {
	*this = other;
}

RPN& RPN::operator=(const RPN& other) {
	if (this != &other) {
		this->_input = other._input;
	}
	return (*this);
}

void RPN::parseInput(const std::string &str) {
	std::stringstream ss(str);
	std::string token;

	while (ss >> token) {
		if (token.length() == 1 && std::isdigit(token[0])) {
			this->_input.push(token[0] - '0');
		} else if (token == "+") {
			calculateResult(&RPN::_plus);
		} else if (token == "-") {
			calculateResult(&RPN::_minus);
		} else if (token == "*") {
			calculateResult(&RPN::_multiply);
		} else if (token == "/") {
			calculateResult(&RPN::_divide);
		} else {
			throw std::runtime_error("Error");
		}
	}
	if (this->_input.size() != 1) {
		throw std::runtime_error("Error");
	}
}

void RPN::calculateResult(double (RPN::*op)(double a, double b)) {
	if (this->_input.size() < 2) {
		throw std::runtime_error("Error");
	}
	double b = this->_input.top();
	this->_input.pop();
	double a = this->_input.top();
	this->_input.pop();

	double res = (this->*op)(a, b);
	this->_input.push(res);
}

double RPN::getResult() const {
	if (this->_input.size() != 1) {
		throw std::runtime_error("Error");
	}
	return this->_input.top();
}

double RPN::_plus(double a, double b) {
	return (a + b);
}

double RPN::_minus(double a, double b) {
	return (a - b);
}

double RPN::_multiply(double a, double b) {
	return (a * b);
}

double RPN::_divide(double a, double b) {
	if (b == 0) {
		throw std::runtime_error("Error");
	}
	return (a / b);
}
