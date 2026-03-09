#ifndef SPAN_HPP
# define SPAN_HPP
#include <exception>
#include <iostream>
#include <vector>
#include <ostream>

class Span 
{
	private:
		unsigned int 	max_size;
		std::vector<int>	vector;
		Span();	
	public:
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();
		void 	addNumber(int n);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;

		class OutOfBound : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class InvalidSpan : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
		void 	printer(void);
};


#endif // !SPAN_HPP
