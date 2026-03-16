#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	(void)argc;
	BitcoinExchange btc;
	btc.loadDataset(argv[1]);
	return (0);
}
