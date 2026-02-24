#ifndef ARRAY_HPP
# define ARRAY_HPP 

#include <exception>
#include <ostream>
#include <iostream>

template<typename T>
class Array {
	private:
		T* arr;
		unsigned int _size;
	public:
		Array() : arr(new T()), _size(0){} ;

		Array(const unsigned int n) : arr(new T[n]), _size(n) {};

		Array(const Array& other) : arr(new T[other.size()]), _size(other._size){
			for (unsigned int i = 0; i < this->_size; i++)
				this->arr[i] = other.arr[i];
		};

		Array& operator=(const Array& other){
			if (this != &other){
				delete [] this->arr;
				this->arr = new T[other._size];
				this->_size = other._size;
			}
			return (*this);
		};

		~Array(){delete[]arr;}; 


		unsigned int 	size() const {
			return (this->_size);	
		};

		class OutOfBounds : public std::exception {
			public:
				virtual const char* what() const throw() { return "Out of Bounds"; }
		};

		// overload [] ?.. ig so
		T& operator[](unsigned int i){
			if (i > this->_size)
				throw OutOfBounds();
			return (this->arr[i]);
		}
};
//std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>arr){
	for (unsigned int i(0); i < arr.size(); i++)
		std::cout << arr[i] << " ";
	return os;
}

#endif
