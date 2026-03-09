#include "Span.hpp"
#include <algorithm>
#include <vector>

Span::Span(unsigned int N) : max_size(N), vector(0) {};

Span::Span(const Span& other)
{
	*this = other;
}

Span &Span::operator=(const Span& other)
{
	if (this != &other)
	{
		this->max_size = other.max_size;
		this->vector = other.vector;
	}
	return *this;
}

Span::~Span(){};

void 	Span::addNumber(int n){
	if (this->vector.size() == this->max_size)
		throw Span::OutOfBound();
	this->vector.push_back(n);
}

unsigned int 	Span::shortestSpan() const
{
	if (vector.size() < 2)
		throw Span::InvalidSpan();

	std::vector<int> temp(vector);
	std::sort(temp.begin(), temp.end());
	int result;
	result = temp.at(0) - temp.at(1);
	for (size_t i = 1; i < temp.size() - 1; ++i)
	{
		int j = temp[i + 1] - temp[0];
		if (j < result)
			result = j;
	}
	return result;	
}

unsigned int Span::longestSpan() const
{
	std::vector<int> temp(vector);
	if (temp.size() < 2)
		throw Span::InvalidSpan();

	int min = *std::min_element(temp.begin(), temp.end());
	int max = *std::max_element(temp.begin(), temp.end());
	return (abs(max-min));
}

void Span::printer()
{
	std::vector<int> temp(vector);
	std::vector<int>::const_iterator it;

	for (it = temp.begin(); it != temp.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

char const* Span::OutOfBound::what() const throw() {
	return "Invalid Size";
}

char const* Span::InvalidSpan::what() const throw(){
	return "Invalid number of elements";
}
