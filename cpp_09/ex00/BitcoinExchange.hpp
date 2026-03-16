#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <map>

class BitcoinExchange {
	private:
		double	_price;
		std::map<std::string, float> _btc;
	
	public:
		BitcoinExchange();
		~BitcoinExchange();	
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(BitcoinExchange const & other);

		void 	loadDataset(const char* filename);
		void 	getBtcValue(std::map<std::string, float>& btc, float target);	

};


#endif // !BITCOINEXCHANGE_HPP
