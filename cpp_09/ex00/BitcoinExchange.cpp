#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
BitcoinExchange::BitcoinExchange() : _price(0), _btc() {}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	this->_price = other._price;
	this->_btc = other._btc;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const & other)
{
	if (this != &other){
		this->_price = other._price;
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

void 	BitcoinExchange::loadDataset(const char * filename)
{
	std::ifstream d;
	d.exceptions(std::ifstream::badbit);
	d.open(filename);
	if (!d.is_open())
		throw std::ifstream::failure("Couldn't Open File");

	std::string line;
	std::string token;
	std::getline(d, line);
	while (std::getline(d, line))
	{
		std::stringstream ss(line);
		std::string date;
		std::string value;
		ss >> line;
		int pos = line.find(',');
		date = line.substr(0, pos);
		value = line.substr(pos+1, std::string::npos);
		_btc[date] = std::strtof(value.c_str(), NULL);
	}
	printMap(_btc);
}



