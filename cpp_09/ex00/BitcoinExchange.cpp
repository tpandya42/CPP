#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const char *inputFile) {
	loadDataset();
	parseInputFile(inputFile);
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	this->_btc = other._btc;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const & other) {
	if (this != &other) {
		this->_btc = other._btc;
	}
	return (*this);
}

void BitcoinExchange::loadDataset() {
	std::ifstream d("data.csv");
	if (!d.is_open()) {
		throw std::runtime_error("Error: could not open database (data.csv).");
	}

	std::string line;
	int i = 0;
	while (std::getline(d, line)) {
		if (line.empty())
			continue;
		if (i == 0) {
			if (line == "date,exchange_rate") {
				i++;
				continue;
			}
		}
		size_t pos = line.find(',');
		if (pos != std::string::npos) {
			std::string date = line.substr(0, pos);
			std::string value_str = line.substr(pos + 1);
			char *endptr;
			double value = std::strtod(value_str.c_str(), &endptr);
			_btc[date] = value;
		}
		i++;
	}
}

double BitcoinExchange::calculateValue(const std::string& date) {
	std::map<std::string, double>::const_iterator it = _btc.lower_bound(date);
	if (it == _btc.end() || it->first != date) {
		if (it == _btc.begin()) {
			// if date is earlier than the earlist date... so give it the next one.. i mean the closest one.
			return it->second;
		}
		--it;
	}
	return it->second;
}

bool BitcoinExchange::validDate(const std::string &date) {
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;

	std::string y_str = date.substr(0, 4);
	std::string m_str = date.substr(5, 2);
	std::string d_str = date.substr(8, 2);

	for (size_t i = 0; i < 4; i++) {
		if (!std::isdigit(y_str[i])) return false;
	}
	for (size_t i = 0; i < 2; i++) {
		if (!std::isdigit(m_str[i])) return false;
		if (!std::isdigit(d_str[i])) return false;
	}

	int year = std::atoi(y_str.c_str());
	int month = std::atoi(m_str.c_str());
	int day = std::atoi(d_str.c_str());

	if (year <= 0)
		return false;
	if (month < 1 || month > 12)
		return false;

	int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	// Leap year check
	if (month == 2) {
		bool is_leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (is_leap)
			days_in_month[1] = 29;
	}

	if (day < 1 || day > days_in_month[month - 1])
		return false;

	return true;
}

void BitcoinExchange::parseInputFile(const char *filename) {
	std::ifstream d(filename);
	if (!d.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	int row = 0;

	while (std::getline(d, line)) {
		if (line.empty())
			continue;
		if (row == 0) {
			row++;
			if (line == "date | value") {
				continue;
			}
		}

		size_t delim_pos = line.find(" | ");
		if (delim_pos == std::string::npos) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, delim_pos);
		std::string value_str = line.substr(delim_pos + 3);

		// Some input checks T - T
		if (!validDate(date)) {
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}

		if (value_str.empty()) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		char *endptr;
		double v = std::strtod(value_str.c_str(), &endptr);
		if (endptr == value_str.c_str() || *endptr != '\0') {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (v < 0) {
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if (v > 1000) {
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}

		double rate = calculateValue(date);
		std::cout << date << " => " << value_str << " = " << rate * v << std::endl;
	}
}
