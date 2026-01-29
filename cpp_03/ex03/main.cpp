#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap beta("beta");
	DiamondTrap alpha(beta);
	DiamondTrap gamma("a");

	beta.whoAmI();
	alpha.whoAmI();
	gamma.whoAmI();

	gamma = beta;
	gamma.whoAmI();

	beta.attack("SOMEONE");
	beta.takeDamage(10);
	beta.beRepaired(19);

	return (0);
}
