#ifndef SPAN_HPP
# define SPAN_HPP

#include <exception>
#include <iostream>
#include <vector>

class Span 
{
	private:
		unsigned int		_maxSize;
		std::vector<int>	_data;
		Span();
	public:
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void			addNumber(int n);
		template<typename T>
		void			addRange(T begin, T end);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;

		class SpanFullException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class NoSpanException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

template<typename T>
void Span::addRange(T begin, T end)
{
	while (begin != end)
	{
		addNumber(*begin);
		++begin;
	}
}

#endif // !SPAN_HPP
