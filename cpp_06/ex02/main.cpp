#include "Base.hpp"


int main(void)
{
	Base *base;


	base = generate();
	identify(base);
	identify(*base);

	delete base;
	std::cout << std::endl;

	base = generate();
	identify(base);
	identify(*base);
	
	delete base;
	std::cout << std::endl;
	
	base = generate();
	identify(base);
	identify(*base);
	
	delete base;
	std::cout << std::endl;

	base = generate();
	identify(base);
	identify(*base);
	
	delete base;
	return (0);
}
