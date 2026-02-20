#include "Intern.hpp"
#include "AForm.hpp"
#include <string>
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(){}
Intern::Intern(const Intern& other) { *this = other; }
Intern& Intern::operator=(const Intern& other){
	if (this != &other)
	{
		*this = other;
	}
	return (*this);
}
Intern::~Intern(){}

AForm* Intern::makeForm(const std::string& formName, const std::string& formTarget)
{
	AForm* forms[] = {
		new RobotomyRequestForm(formTarget),
		new ShrubberyCreationForm(formTarget),
		new PresidentialPardonForm(formTarget)
	};

	std::string formNames[] = {
		"robotomy request",
		"presidential pardon",
		"shrubbery creation"
	};

	for (int i(0); i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return forms[i];
		}
	}
	std::cout << "Sad.. Intern was unable to create " << formName << " form..."<< std::endl;
	return nullptr;	
}
