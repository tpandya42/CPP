#include "Contact.hpp"

Contact::Contact()
	: _firstName(""), _lastName(""), _nickName(""), _phoneNumber(""), _darkestSecret("")
{
}

Contact::~Contact()
{
}

void	Contact::setFirstName(std::string s)
{
	this->_firstName = s;
}

void	Contact::setLastName(std::string s)
{
	this->_lastName = s;
}


void	Contact::setNickname(std::string s)
{
	this->_nickName = s;
}


void	Contact::setPhoneNumber(std::string s)
{
	this->_phoneNumber = s;
}

void	Contact::setDarkestSecret(std::string s)
{
	this->_darkestSecret = s;
}


std::string Contact::getFirstName() const
{
	return this->_firstName;
}

std::string Contact::getLastName() const
{
	return this->_lastName;
}

std::string Contact::getNickname() const
{
	return this->_nickName;
}

std::string Contact::getPhoneNumber() const
{
	return this->_phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
	return this->_darkestSecret;
}
