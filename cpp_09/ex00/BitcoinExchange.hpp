#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <exception>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

class BitcoinExchange {
	private:
		std::map<std::string, double> _btc;
		BitcoinExchange();
	
	public:
		BitcoinExchange(const char *inputFile);
		~BitcoinExchange();	
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(BitcoinExchange const & other);

		void 	loadDataset();
		void 	parseInputFile(const char *filename);
		double 	calculateValue(const std::string& date);
		static bool validDate(const std::string &date);
};

#endif // !BITCOINEXCHANGE_HPP
