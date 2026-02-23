#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Default"), sign(false), toSign(150), toExec(150) {}

Form::Form(std::string name, bool sign, const int toSign, const int toExec) : name(name), sign(sign), toSign(toSign), toExec(toExec) {
	if (toSign < 1 || toExec < 1)
		throw Form::GradeTooHighException();
	if (toSign > 150 || toExec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& other) : sign(other.sign), toSign(other.toSign), toExec(other.toExec), name(other.name){}


Form& Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->sign = other.sign;
	}
	return (*this);
}

Form::~Form(){}

// Getters
std::string Form::getName()const{
	return (this->name);
}

bool Form::getSign()const{
	return (this->sign);
}

int	Form::getToSign()const{
	return (this->toSign);
}

int Form::getToExec()const{
	return (this->toExec);
}


// Execptions
const char* Form::GradeTooHighException::what() const throw(){
	return "Grade is just too high.. can't help it";
}

const char* Form::GradeTooLowException::what() const throw(){
	return "Grade is just tooo low.. Can't help it..";
}

// THe beSigned (ig it makes sense)
void	Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->toSign)
		throw Form::GradeTooLowException();
	this->sign = true;
}






std::ostream& operator<<(std::ostream& os, const Form& f) {
	// will print all the info after implementing getters
	os << f.getName() << "is signed ?... let's see" << f.getSign() <<" good you should now know if it is signed or not... lets move on to grade required for signing and executing respectively... Grade to sign: " << f.getToSign() << " , grade to execute: "<<f.getToExec() << " perfect.. that should be it for now " << std::endl;
	return os;
}


