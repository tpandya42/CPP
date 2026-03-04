#ifndef ARRAY_HPP
# define ARRAY_HPP 

#include <exception>
#include <ostream>
#include <cstdlib>

template<typename T>
class Array {
	private:
		T* arr;
		unsigned int _size;
	public:
		Array();

		Array(const unsigned int n);

		Array(const Array& other);

		Array& operator=(const Array& other);

		~Array(); 

		unsigned int 	size() const;

		class OutOfBounds : public std::exception {
			public:
				virtual const char* what() const throw() { return "Out of Bounds exception"; }
		};

		T& operator[](unsigned int i);
		const T& operator[](unsigned int i) const;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr);

#include "Array.tpp"

#endif
