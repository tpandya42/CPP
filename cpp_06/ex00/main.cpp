#include "ScalerConverter.hpp"
#include <iostream>

void run_test(const std::string& literal) {
    std::cout << "Convert: " << literal << std::endl << std::endl;
    ScalerConverter::convert(literal);
    std::cout << std::endl;
}

int main(int argc, char **argv) {
    if (argc == 2) {
        ScalerConverter::convert(argv[1]);
    } else {
        
		std::cout << "TEST ROUND 1... PDF EXAMPLES" << std::endl;
        run_test("0");
        run_test("nan");
        run_test("42.0f");

		std::cout << "TEST ROUND 2... CHAR TESTs" << std::endl;
        run_test("c");
        run_test("a");

		std::cout << "TEST ROUND 3... INT tests" << std::endl;
        run_test("-42");
        run_test("42");
        run_test("2147483647"); 
		run_test("-2147483648");

		std::cout << "TEST ROUND 4... FlOAT TESTS" << std::endl;
        run_test("-4.2f");
        run_test("4.2f");
        run_test("42f");

		std::cout << "TEST ROUND 5... DOUBLE TESTS" << std::endl;
        run_test("0.0");
        run_test("-4.2");
        run_test("4.2");
        run_test("42.");

		std::cout << "TEST ROUND 6... Pseudo-literal tests" << std::endl;
        run_test("nanf");
        run_test("-inf");
        run_test("+inf");
        run_test("-inff");
        run_test("+inff");

		std::cout << "TEST ROUND 7... OVERFLOW TESTS" << std::endl;
        run_test("2147483648");
        run_test("-2147483649");
		run_test("3.4028235e39"); 

		std::cout << "TEST ROUND 8... ERROR cASES" << std::endl;
        run_test("hello");
        run_test("42.42.42");
        run_test("42a");
        run_test(".");
        run_test("f");
    }
    return 0;
}
