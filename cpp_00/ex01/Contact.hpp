#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkestSecret;

	public:
		Contact();
		~Contact();

		void setFirstName(std::string s);
		void setLastName(std::string s);
		void setNickname(std::string s);
		void setPhoneNumber(std::string s);
		void	setDarkestSecret(std::string s);

		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickname() const;
		std::string	getPhoneNumber() const;
		std::string	getDarkestSecret() const;
};

#endif
