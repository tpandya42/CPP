#include "ShrubberyCreationForm.hpp"


// For now.. cause it makes no sense to me
//ShrubberyCreationForm::ShrubberyCreationForm() : AForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const name, bool sign, const int toSign, const int toExec) : AForm(name, sign, toSign, toExec) {
	if (toSign > 146)
		AForm::GradeTooLowException;
	if (toExec > 137)
		AForm::GradeTooLowException;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : name(other.name), sign(other.sign), toSign(other.toSign), toExec(other.toExec){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		this->sign = other.sign;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void	ShrubberyCreationForm::Shrubby()const {

}
