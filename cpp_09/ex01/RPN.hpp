#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <list>
#include <sstream>
#include <string>
#include <cstdlib>
#include <stdexcept>

class RPN {
	private:
		std::stack<double, std::list<double> > _input;
		double _plus(double a, double b);
		double _minus(double a, double b);
		double _multiply(double a, double b);
		double _divide(double a, double b);

	public:
		RPN();
		~RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);

		void 	parseInput(const std::string &str);
		void 	calculateResult(double (RPN::*op)(double a, double b));
		double 	getResult() const;
};

#endif
