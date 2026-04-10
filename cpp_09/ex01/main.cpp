#include "RPN.hpp"
#include <exception>

int 	main(int argc, char **argv)
{
	RPN test;

	if (argc == 2)
	{
		try {
			test.parseInput(argv);	
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;	
		}
	}
	return (0);
}
