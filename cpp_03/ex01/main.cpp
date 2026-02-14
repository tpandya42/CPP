#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap scavTrap("1");

    scavTrap.attack("some target");
    scavTrap.takeDamage(5);
    scavTrap.beRepaired(3);
    scavTrap.guardGate();

    std::cout << std::endl;

    ScavTrap scavTrap2("2");
    scavTrap2.takeDamage(99);
    scavTrap2.takeDamage(1);

    std::cout << std::endl;

    ScavTrap scavTrap3("3");
    for (int i = 0; i < 51; i++)
        scavTrap3.attack("some other target");
    
    std::cout << std::endl;

    ScavTrap scavTrap4("4");
    ScavTrap scavTrap5(scavTrap4);
    scavTrap5.attack("another target");

    std::cout << std::endl;

    ScavTrap scavTrap6("6");
    ScavTrap scavTrap7("7");
    scavTrap7 = scavTrap6;
    scavTrap7.attack("yet another target");

    return 0;
}
