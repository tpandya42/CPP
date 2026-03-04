template<typename T>
Array<T>::Array() : arr(NULL), _size(0) {}

template<typename T>
Array<T>::Array(const unsigned int n) : arr(new T[n]()), _size(n) {}

template<typename T>
Array<T>::Array(const Array& other) : arr(new T[other._size]()), _size(other._size) {
	for (unsigned int i = 0; i < this->_size; i++)
		this->arr[i] = other.arr[i];
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (this != &other)
	{
		delete [] this->arr;
		this->_size = other._size;
		this->arr = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; i++)
			this->arr[i] = other.arr[i];
	}
	return (*this);
}

template<typename T>
Array<T>::~Array() { delete[] arr; }

template<typename T>
unsigned int Array<T>::size() const {
	return (this->_size);
}

template<typename T>
T& Array<T>::operator[](unsigned int i) {
	if (i >= _size)
		throw OutOfBounds();
	return (this->arr[i]);
}

template<typename T>
const T& Array<T>::operator[](unsigned int i) const {
	if (i >= _size)
		throw OutOfBounds();
	return (this->arr[i]);
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr){
	for (unsigned int i = 0; i < arr.size(); i++)
		os << arr[i] << " ";
	return os;
}










