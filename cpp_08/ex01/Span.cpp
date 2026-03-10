#include "Span.hpp"
#include <algorithm>
#include <climits>

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span& other) : _maxSize(other._maxSize), _data(other._data) {}

Span &Span::operator=(const Span& other)
{
	if (this != &other)
	{
		this->_maxSize = other._maxSize;
		this->_data = other._data;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
	if (_data.size() >= _maxSize)
		throw Span::SpanFullException();
	_data.push_back(n);
}

unsigned int Span::shortestSpan() const
{
	if (_data.size() < 2)
		throw Span::NoSpanException();

	std::vector<int> sorted(_data);
	std::sort(sorted.begin(), sorted.end());

	unsigned int minSpan = static_cast<unsigned int>(sorted[1] - sorted[0]);
	for (size_t i = 2; i < sorted.size(); ++i)
	{
		unsigned int diff = static_cast<unsigned int>(sorted[i] - sorted[i - 1]);
		if (diff < minSpan)
			minSpan = diff;
	}
	return minSpan;
}

unsigned int Span::longestSpan() const
{
	if (_data.size() < 2)
		throw Span::NoSpanException();

	int min = *std::min_element(_data.begin(), _data.end());
	int max = *std::max_element(_data.begin(), _data.end());
	return static_cast<unsigned int>(max - min);
}

char const* Span::SpanFullException::what() const throw() {
	return "Cannot add: Span is full";
}

char const* Span::NoSpanException::what() const throw() {
	return "Not enough elements to find a span";
}
