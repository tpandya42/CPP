template<typename T>
MutantStack<T>::MutantStack(){};

template<typename T>
MutantStack<T>::~MutantStack(){};

template<typename T>
MutantStack<T>::MutantStack(const MutantStack& other)
{
	*this = other;		
}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other)
{
	if(this != &other)
		*this = other;
	return (*this);
}

template<typename T>
typename MutantStack<T>::it MutantStack<T>::begin(){
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::it MutantStack<T>::end(){
	return this->c.end();
}
