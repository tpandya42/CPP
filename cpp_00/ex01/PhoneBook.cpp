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

void	printer(const std::string& field)
{
	const int  max_w = 10;
	if (field.length() > max_w)
	{
		std::cout << std::setw(max_w) << field.substr(0,9) + ".";
	}
	else
		std::cout << std::setw(max_w) << field;
}

void	PhoneBook::search()
{
	std::cout << std::right;

	std::cout << "--------------------------------------" << std::endl;
	std::cout << "|" << std::setw(10) << "Index"
		  << "|" << std::setw(10) << "First Name"
		  << "|" << std::setw(10) << "Last Name"
		  << "|" << std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << "--------------------------------------" << std::endl;

	int	limit;
	if (this->_isFull == true)
		limit = 8;
	else
		limit = this->_index;

	for (int i = 0; i < limit; i++)
	{
		std::cout << "|" << std::setw(10) << (i + 1);
		std::cout << "|"; printer(this->_contacts[i].getFirstName());
		std::cout << "|"; printer(this->_contacts[i].getLastName());
		std::cout << "|"; printer(this->_contacts[i].getNickname());
		std::cout << "|" << std::endl;
	}

	std::cout << "--------------------------------------" << std::endl;


	

	std::string input;
	int	print_i;

	while (true)
	{
		std::cout << "Enter index of contact to display";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return ;
		if (input.empty())
			continue;

		std::stringstream ss(input);
		if (!(ss >> print_i))
		{
			std::cout << "Invalid input " << std::endl;
			continue;
		}

		char	leftover;
		if (ss.get(leftover))
		{
			std::cout << "Invalid input" << std::endl;
			continue;
		}

		if (print_i >= 1 && print_i <= limit)
		{
			const Contact& c = this->_contacts[print_i - 1];
			std::cout << "\n*** Contact Details ***\n";
			std::cout << "First Name:   " << c.getFirstName() << std::endl;
			std::cout << "Last Name:   " << c.getLastName() << std::endl;
			std::cout << "Nickname:   " << c.getNickname() << std::endl;
			std::cout << "Phone Number:   " << c.getPhoneNumber() << std::endl;
			std::cout << "Darkest Secret:   " << c.getDarkestSecret() << std::endl;
			std::cout << std::endl;
			return ;
		}
		else
			std::cout << "Invalid Index.. Please Try Again" << std::endl;
	}



}
