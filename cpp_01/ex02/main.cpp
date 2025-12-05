#include <iostream>
#include <string>

int	main(void)
{
	std::string line = "HI THIS IS BRAIN";
	std::string *stringPTR = &line;
	std::string &stringREF = line;

	std::cout << "Memory ADDRESS" << std::endl;
	std::cout << "Original variable ADDRESS: " << &line << std::endl;
	std::cout << "Pointer Value which is basically address: " << stringPTR << std::endl;
	std::cout << "Reference Address:  " << &stringREF << std::endl;

	std::cout << "\n Valuessssss" << std::endl;
	std::cout << "Original Value:  " << line << std::endl;
	std::cout << "Value pointed by PTR: " << *stringPTR << std::endl;
	std::cout << "Value referred to by Reference: " << stringREF << std::endl;
	return (0);

}
