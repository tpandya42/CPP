#include "Array.hpp"

template<typename T>
Array::Array() : arr(NULL), _size(0){}

template<typename T>
Array::Array(const unsigned int n) : array(new T[n]), _size(n) {}

template<typename T>
Array::Array(const Array& other) : arr(new T[other.size()]) , _size(other.size()) {
	for (unsigned int i = 0; i < this->_size; i++)
		this->arr[i] = other.arr[i];
}

template<typename T>
Array::Array& operator=(const Array& other){
	if (this != &other)
	{
		delete [] this->arr;
		this->_size = other.size();
		this->arr = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; i++)
			this->arr[i] = other.arr[i];
	}
	return (*this);
}

Array::~Array(){ delete[] array; }  

unsigned int	Array::size() const {
	return (this->_size);
}

template<typename T>
T& Array::operator[](unsigned int i)
{
	if (i >= _size)
		throw OutofBounds();
	return (this->arr[i]);
}

template<typename T>
const T& Array::operator[](unsigned int i) const {
	if (i >= size)
		throw OutofBounds();
	return (this->arr[i]);
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr){
	for (unsigned int i = 0; i < arr.size(); i++)
		os << arr[i] << " ";
	return os;
}










