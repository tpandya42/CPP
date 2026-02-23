#include "ScalerConverter.hpp"
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <limits>

const char* ScalerConverter::NotDisplayable::what() const throw(){
	return "Not displayable";
}


static bool is_int(const std::string& str){
	if (str.empty())return false;
	size_t	i = (str[0] == '-' || str[0] == '+')? 1 : 0;
	if (i == str.size()) return false;
	for (size_t j = i; j < str.size(); ++j)
		if (!std::isdigit(str[j])) return false;	
	return true;
}

static bool is_char(const std::string& str){
	return str.length() == 1 && !std::isdigit(str[0]);
}

static bool is_float(const std::string& str){
	if (str == "-inff" || str == "+inff" || str == "nanf") return true;
	if (str.length() < 2 || str.back() != 'f') return false;
	bool 	dot = false;
	size_t i = (str[0] == '+' || str[0] == '-') ? 1:0;
	if (i == str.length() -1) return false;
	for (size_t j = i; j < str.length() - 1; ++j){
		if (str[j] == '.'){
			if (dot) return false;
			dot = true;
		}
		else if (!std::isdigit(static_cast<unsigned char>(str[j]))) return false;
	}
	return true;
}

static bool is_double(const std::string& str){
    if (str == ".") return false;
    if (str == "-inf" || str == "+inf" || str == "nan") return true;
    if (str.empty()) return false;
    bool dot = false;
    size_t i = (str[0] == '+' || str[0] == '-') ? 1 : 0;
    if (i == str.length())return false;
    for (size_t j = i; j < str.length(); ++j){
        if (str[j] == '.'){
            if (dot) return false;
            dot = true;
        }
        else if (!std::isdigit(static_cast<unsigned char>(str[j])))
			return false;
    }
    return dot;
}

static bool isPseudoLiteral(const std::string& str) {
    return (str == "-inff" || str == "+inff" || str == "nanf"
          || str == "-inf" || str == "+inf"  || str == "nan");
}

// stringstream.. for all the data types.. (T-T)
static int for_int(const std::string& str)
{
    long num;
    std::stringstream ss(str);
    ss >> num;
	if (ss.fail())
		throw std::out_of_range("impossible");
    if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
        throw std::out_of_range("impossible");
    return static_cast<int>(num);
}

static float for_float(const std::string& str)
{
    std::string to_parse = str;
    if (!str.empty() && str.back() == 'f') {
        to_parse = str.substr(0, str.length() - 1);
    }
    float num;
    std::stringstream ss(to_parse);
    ss >> num;
    return num;
}

static double for_double(const std::string& str)
{
    double num;
    std::stringstream ss(str);
    ss >> num;
    return num;
}

// Now also need to make literal print function for all of this types... T-TT-TT-TT-TT-TT-TT-TT-TT-TT-TT-T-TT-TT-TT-TT-TT-TT-TT-TT-TT-TT-TT-T

static void 	printChar(char c){
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(c) << std::endl;
}

static void printInt(int nbr)
{
    if (nbr >= std::numeric_limits<char>::min() && nbr <= std::numeric_limits<char>::max())
    {
        if (isprint(static_cast<char>(nbr)))
            std::cout << "char: '" << static_cast<char>(nbr)  << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    else
        std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << nbr << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(nbr) << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(nbr) << std::endl;
}

static void printFloat(float nbr)
{
    if (std::isnan(nbr) || std::isinf(nbr) || nbr < std::numeric_limits<char>::min() || nbr > std::numeric_limits<char>::max())
        std::cout << "char: impossible" << std::endl;
    else if (isprint(static_cast<char>(nbr)))
        std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    if (std::isnan(nbr) || std::isinf(nbr) || nbr > std::numeric_limits<int>::max() || nbr < std::numeric_limits<int>::min())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(nbr) << std::endl;

	std::cout << std::fixed << std::setprecision(1) << "float: " << nbr << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(nbr) << std::endl;
}

static void printDouble(double nbr)
{
    if (std::isnan(nbr) || std::isinf(nbr) || nbr < std::numeric_limits<char>::min() || nbr > std::numeric_limits<char>::max())
        std::cout << "char: impossible" << std::endl;
    else if (isprint(static_cast<char>(nbr)))
        std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    if (std::isnan(nbr) || std::isinf(nbr) || nbr > std::numeric_limits<int>::max() || nbr < std::numeric_limits<int>::min())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(nbr) << std::endl;

	std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(nbr) << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: " << nbr << std::endl;
}

static void pseudoLiteral(types dest_type, const std::string& pseudo_literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl; 
    if (dest_type == t_float)
    {
		std::cout << "float: " << pseudo_literal << std::endl;
		std::cout << "double: " << pseudo_literal.substr(0, pseudo_literal.length() - 1) << std::endl;
    }
    else if (dest_type == t_double)
    {
		std::cout << "float: " << pseudo_literal + "f" << std::endl;
		std::cout << "double: " << pseudo_literal << std::endl;
    }
}

static types getType (const std::string &str)
{
	if (is_int(str)) return t_int;
	if (is_char(str)) return t_char;
	if (is_float(str)) return t_float;
	if (is_double(str)) return t_double;

	return t_unknown;
}

void ScalerConverter::convert(const std::string& literal)
{
    switch (getType(literal))
    {
        case t_char:
            printChar(literal.at(0));
            break;

        case t_int:
			try {
            	printInt(for_int(literal));
			} catch (const std::out_of_range& e) {
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << std::fixed << std::setprecision(1) << "float: " << for_float(literal) << "f" << std::endl;
				std::cout << std::fixed << std::setprecision(1) << "double: " << for_double(literal) << std::endl;
			}
            break;

        case t_float:
            if (isPseudoLiteral(literal))
                pseudoLiteral(t_float, literal);
            else
                printFloat(for_float(literal));
            break;

        case t_double:
            if (isPseudoLiteral(literal))
                pseudoLiteral(t_double, literal);
            else
                printDouble(for_double(literal));
            break;

        default:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
            break;
    }
}
