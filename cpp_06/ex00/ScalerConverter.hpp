#ifndef SCALERCONVERTER_HPP
#define SCALERCONVERTER_HPP

#include <exception>
#include <iostream>
#include <string>
#include <cctype>
#include <cstddef>
#include <sstream>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <limits>

enum types{
	t_int,
	t_char,
	t_float,
	t_double,
	t_nan,
	t_unknown
};

/*
 * 1. need to check for int, char, float, double, nan and unknown..
 * 2. Error message
 * 3. ahhh also the the PSEUDO_LITERALS.. (will compare the input string directly with em... hardcoding this shit... lessgo) */

class ScalerConverter {
	private:
		ScalerConverter();
		ScalerConverter(const ScalerConverter& other);
		ScalerConverter& operator=(const ScalerConverter& other);
		~ScalerConverter();

	public:
		static void convert(const std::string& literal);

	class NotDisplayable : public std::exception {
		public:
			virtual const char* what() const throw();
	};

};


#endif // !SCALERCONVERTER_HPP
