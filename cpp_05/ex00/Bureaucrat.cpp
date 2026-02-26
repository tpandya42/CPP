#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150) {}

Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other)
		this->grade = other.grade;
	return (*this);
}
Bureaucrat::~Bureaucrat() {}




/* GETTERS */

std::string const & Bureaucrat::getName() const {
	return (this->name);
}

int	Bureaucrat::getGrade() const {
	return (this->grade);
}


/* METHODS FOR NOW IG*/
void	Bureaucrat::incrementGrade() {
	if (this->grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void	Bureaucrat::decrementGrade() {
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}


/* EXCEPTIONSSS*/
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "You Already Doing Good kid!!!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Get your ASS back on that studyDESKK";
}




std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}
