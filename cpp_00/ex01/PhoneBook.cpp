#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
	: _index(0), _isFull(false)
{
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::add()
{
	Contact	tempContact;
	std::string	input;

	while (true)
	{
		std::cout << "Enter First Name" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "Exiting" <<std::endl;
			return ;
		}
		else if (input.empty())
		{
			std::cout << "Put Something Please" << std::endl;
			continue;
		}
		tempContact.setFirstName(input);
		break;
	}

	while (true)
	{
		std::cout << "Enter Last Name" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "Exiting" <<std::endl;
			return ;
		}
		else if (input.empty())
		{
			std::cout << "Put Something Please" << std::endl;
			continue;
		}
		tempContact.setLastName(input);
		break;
	}

	while (true)
	{
		std::cout << "Enter Nickname" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "Exiting" <<std::endl;
			return ;
		}
		else if (input.empty())
		{
			std::cout << "Put Something Please" << std::endl;
			continue;
		}
		tempContact.setNickname(input);
		break;
	}

	while (true)
	{
		std::cout << "Enter Phone Number" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "Exiting" <<std::endl;
			return ;
		}
		else if (input.empty())
		{
			std::cout << "Put Something Please" << std::endl;
			continue;
		}
		tempContact.setPhoneNumber(input);
		break;
	}

	while (true)
	{
		std::cout << "Enter Darkest Secret" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "Exiting" <<std::endl;
			return ;
		}
		else if (input.empty())
		{
			std::cout << "Put Something Please" << std::endl;
			continue;
		}
		tempContact.setDarkestSecret(input);
		break;
	}

	this->_contacts[this->_index] = tempContact;
	this->_index++;
	if (this->_index == 8)
	{
		this->_index= 0;
		this->_isFull = true;
	}
	std::cout << "Contact added successfully" << std::endl;
}
