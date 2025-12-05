#include "Zombie.hpp"

int	main(void)
{
	std::cout << "TEST 1: STACK ALLOCATION" << std::endl;
	randomChump("Rikku");
	std::cout << "Rikku destroyed... " << std::endl;

	std::cout << "TEST 2: HEAP ALLOCATION" << std::endl;
	Zombie *blahblah = newZombie("Rikku_Again");
	std::cout << "Hopefully its created" << std::endl;
	blahblah->announce();

	std::cout << "Deleting it" << std::endl;
	delete (blahblah);
	
	std::cout << "Hopefully its Gone... Thank you for Testing " << std::endl;
	return (0);
}
