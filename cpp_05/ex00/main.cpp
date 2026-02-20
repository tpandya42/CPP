#include "Bureaucrat.hpp"
#include <iostream>

void run_test(std::string const & test_name, void (*test_func)()) {
	std::cout << "--- Running test: " << test_name << " ---" << std::endl;
	test_func();
	std::cout << "--- Test passed: " << test_name << " ---\n" << std::endl;
}

void test_valid_creation() {
	Bureaucrat b("Turing", 2);
	std::cout << b << std::endl;
}

void test_too_high_creation() {
	try {
		Bureaucrat b("Invalid", 0);
	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}
}

void test_too_low_creation() {
	try {
		Bureaucrat b("Invalid", 151);
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}
}

void test_increment() {
	Bureaucrat b("Babbage", 2);
	std::cout << "Initial: " << b << std::endl;
	b.incrementGrade();
	std::cout << "After increment: " << b << std::endl;
}

void test_increment_limit() {
	Bureaucrat b("Lovelace", 1);
	std::cout << "Initial: " << b << std::endl;
	try {
		b.incrementGrade();
	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}
}

void test_decrement() {
	Bureaucrat b("Hopper", 149);
	std::cout << "Initial: " << b << std::endl;
	b.decrementGrade();
	std::cout << "After decrement: " << b << std::endl;
}

void test_decrement_limit() {
	Bureaucrat b("Ritchie", 150);
	std::cout << "Initial: " << b << std::endl;
	try {
		b.decrementGrade();
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}
}

int main(void) {
	run_test("Valid Creation", &test_valid_creation);
	run_test("Too High Creation", &test_too_high_creation);
	run_test("Too Low Creation", &test_too_low_creation);
	run_test("Increment Grade", &test_increment);
	run_test("Increment Grade Limit", &test_increment_limit);
	run_test("Decrement Grade", &test_decrement);
	run_test("Decrement Grade Limit", &test_decrement_limit);
	return 0;
}
