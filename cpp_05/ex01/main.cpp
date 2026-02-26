#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void print_header(const std::string& title) {
    std::cout << "\n" << title << std::endl;
}

int main() {

    print_header("Round 1: Creation");
    try {
        Bureaucrat signer("Signer", 50);
        Form formA("FormA", 100, 100);
        std::cout << signer << std::endl;
        std::cout << formA << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught unexpected exception: " << e.what() << std::endl;
    }

    print_header("Round 2: Invalid Creation.. ofc");
    try {
        Form form_too_high("InvalidHigh", 0, 150);
    } catch (const std::exception& e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }
    try {
        Form form_too_low("InvalidLow", 151, 150);
    } catch (const std::exception& e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }
    try {
        Form form_too_high_exec("InvalidHighExec", 150, 0);
    } catch (const std::exception& e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }
    try {
        Form form_too_low_exec("InvalidLowExec", 150, 151);
    } catch (const std::exception& e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    print_header("Round 3: Successful Signing... hopefully T-T");
    try {
        Bureaucrat high_grade_bur("HighGrade", 10);
        Form easy_form("EasyForm", 20, 20);
        std::cout << "Before signing:\n" << high_grade_bur << "\n" << easy_form << std::endl;
        high_grade_bur.signForm(easy_form);
        std::cout << "\nAfter signing:\n" << easy_form << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught unexpected exception: " << e.what() << std::endl;
    }

    print_header("Round 4: Failure Phase (Low grade) T-T");
    try {
        Bureaucrat low_grade_bur("LowGrade", 80);
        Form hard_form("HardForm", 50, 50);
        std::cout << "Before signing:\n" << low_grade_bur << "\n" << hard_form << std::endl;
        low_grade_bur.signForm(hard_form);
        std::cout << "\nAfter signing attempt:\n" << hard_form << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught unexpected exception: " << e.what() << std::endl;
    } 
    return 0;
}
