#include "Base.hpp"

Base::~Base(){}

Base* generate()
{
	static bool seeded = false;
	if (!seeded) {
		std::srand(std::time(0));
		seeded = true;
	}

	int i = std::rand() % 3;
	switch (i) {
		case 0: return new A;
		case 1: return new B;
		case 2: return new C;
	}
	return nullptr;
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Error" << std::endl;
}

void identify(Base &p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::exception &e) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::exception &e) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::exception &e) {
		std::cout << "Error" << std::endl;
	}	
}
