#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap rikku("Rikku");
	rikku.attack("SOMEONE");
	rikku.takeDamage(30);
	rikku.beRepaired(10);
	rikku.gaurdGate();
	return (0);
}
