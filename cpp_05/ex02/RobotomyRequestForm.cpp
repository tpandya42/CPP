#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target){}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){}

std::string  	RobotomyRequestForm::getTarget () const {
	return (this->target);
}

void	RobotomyRequestForm::exec() const {
	std::cout << " RRRRRRR..... zzuzuzuzuzuzuz....some drilling noiiceddd...slfjalfjs  GRGRRGR BHBHBHBH " << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << this->getTarget() << " has been successfully robotomized!" << std::endl;
	else
		std::cout << "The robotomy procedure on " << this->getTarget() << " has failed." << std::endl;
}
										
