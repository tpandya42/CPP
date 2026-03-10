#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{
	std::vector<int> vec;
	for (int i = 0; i < 10; ++i)
		vec.push_back(i * 3);

	std::cout << "ROUND ! :: WITH VECTOR " << std::endl;
	try {
		std::vector<int>::iterator it = easyfind(vec, 6);
		std::cout << "Found: " << *it << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		easyfind(vec, 42);
	} catch (std::exception& e) {
		std::cout << "42: " << e.what() << std::endl;
	}

	// Test with list
	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);

	std::cout << "ROUND 2 :: WITH LIST" << std::endl;
	try {
		std::list<int>::iterator it = easyfind(lst, 2);
		std::cout << "Found: " << *it << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		easyfind(lst, 99);
	} catch (std::exception& e) {
		std::cout << "99: " << e.what() << std::endl;
	}


	std::vector<int> empty;
	std::cout << "ROUND 3 :: EMPTY CONTAINER" << std::endl;
	try {
		easyfind(empty, 1);
	} catch (std::exception& e) {
		std::cout << "Empty: " << e.what() << std::endl;
	}

	return 0;
}
