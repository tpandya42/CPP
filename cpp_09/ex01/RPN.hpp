#ifndef RPN_HPP
# define RPN_HPP

#include <cmath>
#include <iostream>
#include <algorithm>
#include <stack>
#include <sstream>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include <string>
#include <vector>

class RPN {
	private:
		std::stack<double> _input;
		double _plus(double a, double b);
		double _minus(double a, double b);
		double _multiply(double a, double b);
		double _divide(double a, double b);
	public:
		RPN();
		~RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);

		void 	parseInput(char **argv);
		long 	calculateResult(std::stack<int>& _input);
			
};

#endif
