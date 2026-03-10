#include "Span.hpp"
#include <cstdlib>

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "\nROUND 1:: -> OVERFLOW" << std::endl;
	try {
		sp.addNumber(42);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\nROUND 2:: -> TOO FEW ARGUMENT (InvALID INPUT)" << std::endl;
	Span tiny(1);
	tiny.addNumber(1);
	try {
		tiny.shortestSpan();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\nROUND 3:: -> LOT OF ARGUEMENTS" << std::endl;
	Span big(10000);
	std::vector<int> nums;
	for (int i = 0; i < 10000; ++i)
		nums.push_back(i * 2);
	big.addRange(nums.begin(), nums.end());
	std::cout << "Shortest: " << big.shortestSpan() << std::endl;  // 2
	std::cout << "Longest:  " << big.longestSpan() << std::endl;   // 19998

	std::cout << "\nROUND 4 :: -> ADD FUNCTION OVERFLOW" << std::endl;
	Span small(3);
	small.addNumber(1);
	std::vector<int> extra;
	extra.push_back(2);
	extra.push_back(3);
	extra.push_back(4);
	try {
		small.addRange(extra.begin(), extra.end());
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
