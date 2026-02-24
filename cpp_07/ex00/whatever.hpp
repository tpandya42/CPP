#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
#include <string>
#include <utility>

template<typename T>
void 	swap(T &x, T &y){
	T temp = y;
	y = x;
	x = temp;
}

template<typename T>
T min(T &x, T &y)
{
	if (x < y)
		return x;
	if (x == y)
		return y;
	else
		return y;
}

template<typename T>
T max(T &x, T &y)
{
	if (x > y)
		return x;
	else if (y > x)
		return y;
	else
		return y;	
}


#endif
