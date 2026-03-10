#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack();
		MutantStack(const MutantStack& other);
		MutantStack &operator=(const MutantStack& other);
		~MutantStack();
		typedef typename std::stack<T>::container_type::iterator it;
		it begin();
		it end();	
};

#include "MutantStack.tpp"

#endif
