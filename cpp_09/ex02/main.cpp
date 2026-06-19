#include <exception>
#include <iostream>
#include <sstream>
#include <vector>
#include <deque>

int		main(int argc, char **argv)
{

	try {


		std::vector<int> Vcont;
		std::deque<int>	 Dcont;
		int		value;

		for (int i = 1; i < argc; i++) {
			std::stringstream ss(argv[i]);
			if (!(ss >> value) || !(ss.eof()))
				throw "PARSING ERROR";
			if (value < 0)
				throw "PARSING ERROR";
			Vcont.push_back(value);
			Dcont.push_back(value);
		}
	}
	catch (std::exception *e)
	{
		std::cout << e << std::endl;
	}
	return (0);
}
