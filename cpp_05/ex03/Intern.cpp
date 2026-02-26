#include "Intern.hpp"
#include "AForm.hpp"
#include <string>
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(){}
Intern::Intern(const Intern& other) { (void)other; }
Intern& Intern::operator=(const Intern& other){
	if (this != &other)
	{
	}
	return (*this);
}
Intern::~Intern(){}

static AForm* createRobotomy(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

static AForm* createShrubbery(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& formTarget)
{
	struct Formss {
		const char* name;
		AForm* (*create_function)(const std::string&);
	};

	static const Formss yes_formss[] = {
		{"robotomy request", createRobotomy},
		{"presidential pardon", createPresidential},
		{"shrubbery creation", createShrubbery}
	};

	for (size_t i = 0; i < 3; ++i)
	{
		if (formName == yes_formss[i].name)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return yes_formss[i].create_function(formTarget);
		}
	}

	std::cout << "hahah... get me as your intern... i can make any form... T-T> "
		<< formName << " can't be created..." << std::endl;
	return NULL;
}
