#include "Zombie.hpp"
// For handling exit failure if allocation fails.. as far as i understand
#include "cstdlib"

#define SIZE 5
#define NAME "RIKKU"

int	main(void)
{
	Zombie* zombies;
	std::cout << "Creating Horde of size " << SIZE << " and naming them " << NAME << "..." << std::endl;

	zombies = zombieHorde(SIZE, NAME);

	if (!zombies)
	{
		std::cout << "Allocation failed" << std::endl;
		return (EXIT_FAILURE);
	}

	std::cout <<"\n LET'S SEE IF WE DID SOMETHING..... " << std::endl;
	for (int i = 0; i < SIZE; ++i)
	{
		zombies[i].announce();
	}

	std::cout << "\n Deleting All the Zombiesss" << std::endl;
	delete[] zombies;
	std::cout << "---DELETED---" << std::endl;
	return (0);
}
