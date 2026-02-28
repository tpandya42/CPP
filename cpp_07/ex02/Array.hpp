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
		Array() : arr(NULL), _size(0) {};

		Array(const unsigned int n) : arr(new T[n]), _size(n) {};

		Array(const Array& other) : arr(new T[other.size()]), _size(other.size()){
			for (unsigned int i = 0; i < this->_size; i++)
				this->arr[i] = other.arr[i];
		};

		Array& operator=(const Array& other){
			if (this != &other){
				delete [] this->arr;
				this->_size = other.size();
				this->arr = new T[this->_size];
				for (unsigned int i = 0; i < this->_size; i++)
					this->arr[i] = other.arr[i];
			}
			return (*this);
		};

		~Array(){ delete[] arr; }; 

		unsigned int 	size() const {
			return (this->_size);	
		};

		class OutOfBounds : public std::exception {
			public:
				virtual const char* what() const throw() { return "Out of Bounds exception"; }
		};

		T& operator[](unsigned int i){
			if (i >= _size)
				throw OutOfBounds();
			return (this->arr[i]);
		}

		const T& operator[](unsigned int i) const {
			if (i >= _size)
				throw OutOfBounds();
			return (this->arr[i]);
		}
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr){
	for (unsigned int i = 0; i < arr.size(); i++)
		os << arr[i] << " ";
	return os;
}

#endif
