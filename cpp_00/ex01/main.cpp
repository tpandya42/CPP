#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook myPb;
	std::string input;

	while (true)
	{
		std::cout << "\n Enter Command (ADD, SEARCH, or EXIT): ";
		if (!std::getline(std::cin, input))
		{
			std::cout << "error" << std::endl;
			break;
		}
		if (input == "ADD")
			myPb.add();
		else if (input == "SEARCH")
			myPb.search();
		else if (input == "EXIT")
		{
			std::cout << "Exiting PhoneBook. Contacts lost forever!" << std::endl;
			break;
		}
		else
			std::cout << "Invalid Command" << std::endl;
	}
	return (0);
}
