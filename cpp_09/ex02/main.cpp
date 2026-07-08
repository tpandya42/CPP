#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <sys/time.h>
#include <iomanip>
#include <stdexcept>

static double get_time_us() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (static_cast<double>(tv.tv_sec) * 1000000.0) + tv.tv_usec;
}

int		main(int argc, char **argv)
{
	try {
		if (argc < 2) {
			throw std::runtime_error("Error: Please provide positive integers as arguments.");
		}

		std::vector<int> Vcont;
		std::deque<int>	 Dcont;

		for (int i = 1; i < argc; i++) {
			std::stringstream ss(argv[i]);
			double val_d;
			if (!(ss >> val_d) || !(ss.eof()))
				throw std::runtime_error("Error");
			if (val_d < 0 || val_d > 2147483647.0 || val_d != static_cast<int>(val_d))
				throw std::runtime_error("Error");
			
			int value = static_cast<int>(val_d);
			Vcont.push_back(value);
			Dcont.push_back(value);
		}

		std::cout << "Before: ";
		for (size_t i = 0; i < Vcont.size(); ++i) {
			std::cout << Vcont[i] << " ";
		}
		std::cout << std::endl;

		double v_start = get_time_us();
		std::vector<int> sorted_v = mergeInsertSort(Vcont);
		double v_end = get_time_us();
		double v_time = v_end - v_start;

		double d_start = get_time_us();
		std::deque<int> sorted_d = mergeInsertSort(Dcont);
		double d_end = get_time_us();
		double d_time = d_end - d_start;

		std::cout << "After:  ";
		for (size_t i = 0; i < sorted_v.size(); ++i) {
			std::cout << sorted_v[i] << " ";
		}
		std::cout << std::endl;

		std::cout << "Time to process a range of " << Vcont.size() 
		          << " elements with std::vector : " << std::fixed << std::setprecision(5) << v_time << " us" << std::endl;
		std::cout << "Time to process a range of " << Dcont.size() 
		          << " elements with std::deque  : " << std::fixed << std::setprecision(5) << d_time << " us" << std::endl;

	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return (0);
}
