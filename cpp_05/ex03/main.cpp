#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>

void print_header(const std::string& title) {
    std::cout << "\n---> " << title << std::endl;
}

int main() {
    Intern someRandomIntern;
    AForm* form;

    print_header("Round 1: Create Robotomy Request Form");
    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form) {
        Bureaucrat bob("Bob", 1);
        bob.signForm(*form);
        bob.executeForm(*form);
        delete form;
    }

    print_header("Round 2: Create Presidential Pardon Form");
    form = someRandomIntern.makeForm("presidential pardon", "shittyPresidentForm");
    if (form) {
        delete form;
    }

    print_header("Round 3: Create Shrubbery Creation Form");
    form = someRandomIntern.makeForm("shrubbery creation", "shrubbberyyyyyyy");
    if (form) {
        delete form;
    }

    print_header("Round 4: Create Invalid Form");
    form = someRandomIntern.makeForm("invalid form", "target");
    if (form) {
        std::cout << "Error: Invalid form was created!\n";
        delete form;
    }

    return 0;
}
