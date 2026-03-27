#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <map>

class BitcoinExchange {
	private:
		std::map<std::string, float> _btc;
		BitcoinExchange();
	
	public:
		BitcoinExchange(const char *inputFile);
		~BitcoinExchange();	
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(BitcoinExchange const & other);

		void 	loadDataset();
		void parseInputFile(const char *filename);
		float calculateValue(std::string& date);
		static bool validDate(const tm &date);

};
#endif // !BITCOINEXCHANGE_HPP
