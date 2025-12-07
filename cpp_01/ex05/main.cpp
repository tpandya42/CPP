#include "Harl.hpp"

int	main(void)
{
	Harl harl;

	std::cout << "Test: Debug" << std::endl;
	harl.complain("DEBUG");

	std::cout << "Test: INFO" << std::endl;
	harl.complain("INFO");

	std::cout << "Test: warning" << std::endl;
	harl.complain("WARNING");

	std::cout << "Test: Error" << std::endl;
	harl.complain("ERROR");

	std::cout << "Test: RANDOM SHIT" << std::endl;
	harl.complain("HAHAHAH");

	std::cout << "Test: EMPTY STRING" << std::endl;
	harl.complain("");

	return (0);

}
