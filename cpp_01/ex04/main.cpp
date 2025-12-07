#include <iostream>
#include <string>
#include <fstream>
#include <iterator>

std::string rep_s(std::string str, const std::string& s1, const std::string& s2)
{
	size_t pos = 0;
	while ((pos = str.find(s1, pos)) != std::string::npos)
	{
		str.erase(pos, s1.length());
		str.insert(pos, s2);
		pos += s2.length();
	}
	return str;
}

int	beta_sed(const std::string& filename, const std::string& s1, const std::string& s2)
{
	if (s1.empty())
	{
		std::cerr << "S1 EMPTY" << std::endl;
		return (1);
	}

	std::ifstream ifs(filename.c_str());
	if (!ifs.is_open())
	{
		std::cerr << "COuld not open the file" << std::endl;
		return (1);
	}

	std::ofstream ofs((filename + ".replace").c_str());
	if (!ofs.is_open())
	{
		std::cerr << "Could not create output file" << std::endl;
		return (1);
	}

	std::string file_stuff((std::istreambuf_iterator<char>(ifs)),
				std::istreambuf_iterator<char>());

	std::string new_file = rep_s(file_stuff, s1, s2);
	ofs << new_file;
	return (0);

}

int	main(int argc, char **av)
{
	if (argc != 4)
	{
		std::cout << "Incorrect Input " << std::endl;
		return (1);
	}
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	
	return (beta_sed(filename, s1, s2));

}
