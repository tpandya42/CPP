#include "BitcoinExchange.hpp"
#include <exception>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <cstdlib>
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const char *inputFile){
	loadDataset();
	parseInputFile(inputFile);
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	this->_btc = other._btc;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const & other)
{
	if (this != &other){
		this->_btc = other._btc;
	}
	return (*this);
}

void 	printMap(std::map<std::string, float> btc)
{
	for (std::map<std::string, float>::iterator it = btc.begin(); it != btc.end(); ++it)
	{
		std::cout << it->first << " : " << it->second << std::endl;
	}
}

void 	BitcoinExchange::loadDataset()
{
	std::ifstream d;
	d.exceptions(std::ifstream::badbit);
	d.open("data.csv");
	if (!d.is_open())
		throw std::ifstream::failure("Couldn't Open File");

	std::string line;
	std::string token;
	int i = 0;
	std::getline(d, line);
	while (std::getline(d, line))
	{
		if (line == "date, exchange_rate" && i++ == 0)
			continue;
		std::stringstream ss(line);
		std::string date;
		std::string value;
		ss >> line;
		int pos = line.find(',');
		date = line.substr(0, pos);
		value = line.substr(pos+1, std::string::npos);
		_btc[date] = std::strtof(value.c_str(), NULL);
		i++;
	}
	// if (i == 0)
	// 	throw someError();
	printMap(_btc);
}

float 	BitcoinExchange::calculateValue(std::string& date)
{
	std::map<std::string, float>::iterator it  = _btc.lower_bound(date);
	if (it == _btc.begin())
		return it->second;
	if (it == _btc.end() || it->first != date)
		it--;
	return it->second;
}

bool 	BitcoinExchange::validDate(const tm &date)
{
    static const int days_in_month[] = {
        31, // Jan
        28, // Feb
        31, // Mar
        30, // Apr
        31, // May
        30, // Jun
        31, // Jul
        31, // Aug
        30, // Sep
        31, // Oct
        30, // Nov
        31  // Dec
    };

    int days = days_in_month[date.tm_mon];

    // !!!! LEAP YEARRR CHECKKK (EHHH)
    if (date.tm_mon == 1) {
        int year = date.tm_year + 1900;
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            days = 29;
    }

    return date.tm_mday >= 1 && date.tm_mday <= days;
}

void BitcoinExchange::parseInputFile(const char *filename)
{
	std::ifstream d(filename);
	std::string line;
	int 	row = 0;

	while (std::getline(d, line))
	{
		try {
			if (row == 0) {
				if (line != "date | value") {
					throw std::runtime_error("Bad Input File");
				}
				row++;
				continue;
			}

			if (line.find(" | ") == std::string::npos)
				throw std::runtime_error("Wrong Syntax");

			std::string date = line.substr(0, line.find(" " ));
			std::string value = line.substr(line.find(" | ") + 3);
			if (date.empty() || value.empty())
				throw std::runtime_error("Invalid Input File");
			struct tm tm = {};

			if (!strptime(date.c_str(), "%Y-%m-%d", &tm) || !validDate(tm)){
				throw std::runtime_error("Invalid Date");
			}

			if (!value.empty())
			{
				char *pointer;
				float v = std::strtof(&value[0], &pointer);
				if (v < 0 || v > 1000)
					throw std::runtime_error("Invalid Value");
			}

			std::string dateDate = date;
			float noBTC = std::atof(value.c_str());
			float finalValue = calculateValue(date);
			std::cout << dateDate << "=>" << value << " = " << finalValue * noBTC << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		row++;
	}
	if (row == 0)
		throw std::runtime_error("Empty File");
}

