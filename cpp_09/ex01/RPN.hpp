#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <algorithm>
#include <stack>
#include <sstream>
#include <string>

class RPN {
	private:
		std::stack<std::string> _input;
	
	public:
		RPN();
		~RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);

		void 	parseInput(char **argv);
		long 	calculateResult(std::stack<int>& _input);
};

#endif
