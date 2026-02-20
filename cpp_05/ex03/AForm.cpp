#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Default"), sign(false), toSign(150), toExec(150) {}

AForm::AForm(std::string name, bool sign, const int toSign, const int toExec) : name(name), sign(sign), toSign(toSign), toExec(toExec) {}

AForm::AForm(const AForm& other) : sign(other.sign), toSign(other.toSign), toExec(other.toExec), name(other.name){}


AForm& AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->sign = other.sign;
	}
	return (*this);
}

AForm::~AForm(){}

// Getters
std::string AForm::getName()const{
	return (this->name);
}

bool AForm::getSign()const{
	return (this->sign);
}

int	AForm::getToSign()const{
	return (this->toSign);
}

int AForm::getToExec()const{
	return (this->toExec);
}


// Execptions
const char* AForm::GradeTooHighException::what() const throw(){
	return "Grade is just too high.. can't help it";
}

const char* AForm::GradeTooLowException::what() const throw(){
	return "Grade is just tooo low.. Can't help it..";
}

const char* AForm::FormNotSignedExecption::what() const throw(){
	return "Form is not signed... SORRY T-T";
}

// THe beSigned (ig it makes sense)
void	AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->toSign)
		throw AForm::GradeTooLowException();
	this->sign = true;
}

// Execute function 
void 	AForm::execute(const Bureaucrat & executor) const {
	if (!this->getSign())
		throw AForm::FormNotSignedExecption();
	if (executor.getGrade() > this->getToExec())
		throw AForm::GradeTooLowException();
	this->exec();
}


std::ostream& operator<<(std::ostream& os, const AForm& f) {
	// will print all the info after implementing getters
	os << f.getName() << "is signed ?... let's see" << f.getSign() <<" good you should now know if it is signed or not... lets move on to grade required for signing and executing respectively... Grade to sign: " << f.getToSign() << " , grade to execute: "<<f.getToExec() << " perfect.. that should be it for now " << std::endl;
	return os;
}


