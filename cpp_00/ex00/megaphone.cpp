#include <iostream>
#include <cctype>

int	main(int argc, char **argv)
{
	if (argc < 2){
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
		return (0);
	}
	int	i = 1;
	while (argv[i])
	{
		char	*str = argv[i];
		int j = 0;
		while (str[j])
			std::cout<<static_cast<char>(toupper(str[j++]));
		i++;
	}
	std::cout<<"\n";
	return (0);
}
