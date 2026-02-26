#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

void print_header(const std::string& title) {
    std::cout << "\n\n--- " << title << " ---\n\n";
}

int main() {
    std::srand(std::time(0));

    Bureaucrat boss("Boss", 1);
    Bureaucrat middleManager("MiddleManager", 40);
    Bureaucrat intern("Intern", 140);
    std::cout << boss << std::endl;
    std::cout << middleManager << std::endl;
    std::cout << intern << std::endl;

    ShrubberyCreationForm shrub("Garden");
    RobotomyRequestForm robo("Bender");
    PresidentialPardonForm pardon("Ford");
    std::cout << shrub << std::endl;
    std::cout << robo << std::endl;
    std::cout << pardon << std::endl;
	std::cout << std::endl;

    print_header("ShrubberyCreationForm Tests");
    intern.executeForm(shrub);
    intern.signForm(shrub);
    intern.executeForm(shrub);
    Bureaucrat useless("Useless", 150);
    useless.executeForm(shrub);
	std::cout << std::endl;

    print_header("RobotomyRequestForm Tests");
    intern.signForm(robo);
    middleManager.signForm(robo);
    middleManager.executeForm(robo);
    boss.executeForm(robo);
    boss.executeForm(robo);
    boss.executeForm(robo);


    print_header("PresidentialPardonForm Tests");
    middleManager.signForm(pardon);
    boss.executeForm(pardon);
    boss.signForm(pardon);
    boss.executeForm(pardon);

	// as per subject's requirement... the gracefully commented line should throw error...  T_T
    // AForm* form = new AForm();
    
    return 0;
}
