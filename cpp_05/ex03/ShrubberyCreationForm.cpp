#include "ShrubberyCreationForm.hpp"


// For now.. cause it makes no sense to me
//ShrubberyCreationForm::ShrubberyCreationForm() : AForm(){}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", false, 145, 137), target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target){}


ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}


void 	ShrubberyCreationForm::exec()const {
	std::string fname = this->target + "_shrubbery";
	std::ofstream outfile(fname.c_str());
	if (!outfile)
	{
		std::cerr << "Can't Open file" << std::endl;
		return ;
	}
	outfile << "     /\\ \n"
			   "    /**\\ \n"
			   "   /****\\ \n"
			   "  /******\\ \n"
			   " /********\\ \n"
			   "     |||| \n"
			   "     |||| \n";
	outfile.close();

}                                                                                                  
