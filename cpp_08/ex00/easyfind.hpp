#ifndef EASYFIND_HPP
# define EASYFIND_HPP
#include <iostream>
#include <algorithm>
template<typename T>
void 	easyfind(T& sometype, int x)
{
	if (std::find(sometype.begin(), sometype.end(), x) != sometype.end())
	{
		std::cout << "IT IS PRESENT" << std::endl;
	}
	else {
		std::cout << "IT IS NOT PRESENT" << std::endl;
	}
}


#endif // EASYFIND_HPP
