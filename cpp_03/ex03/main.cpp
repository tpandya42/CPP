#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap diamondTrap("DT-1");

    diamondTrap.attack("some target");
    diamondTrap.takeDamage(5);
    diamondTrap.beRepaired(3);
    diamondTrap.whoAmI();
    diamondTrap.guardGate();
    diamondTrap.highFivesGuys();

    std::cout << "--------------------" << std::endl;

    DiamondTrap diamondTrap2("DT-2");
    diamondTrap2.takeDamage(99);
    diamondTrap2.takeDamage(1);

    std::cout << "--------------------" << std::endl;

    DiamondTrap diamondTrap3("DT-3");
    for (int i = 0; i < 51; i++)
        diamondTrap3.attack("some other target");
    
    std::cout << "--------------------" << std::endl;

    DiamondTrap diamondTrap4("DT-4");
    DiamondTrap diamondTrap5(diamondTrap4);
    diamondTrap5.attack("another target");

    std::cout << "--------------------" << std::endl;

    DiamondTrap diamondTrap6("DT-6");
    DiamondTrap diamondTrap7("DT-7");
    diamondTrap7 = diamondTrap6;
    diamondTrap7.attack("yet another target");

    return 0;
}