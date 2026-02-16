#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap clapTrap("1");

    clapTrap.attack("some target");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(3);
    clapTrap.takeDamage(10);
    clapTrap.beRepaired(5);
    clapTrap.attack("another target");

    std::cout << std::endl;

    ClapTrap clapTrap2("2");
    clapTrap2.takeDamage(9);
    clapTrap2.takeDamage(1);

    std::cout << std::endl;

    ClapTrap clapTrap3("3");
    for (int i = 0; i < 11; i++)
        clapTrap3.attack("some other target");

    std::cout << std::endl;
    
    ClapTrap clapTrap4("4");
    ClapTrap clapTrap5(clapTrap4);
    clapTrap5.attack("another target");

    std::cout << std::endl;

    ClapTrap clapTrap6("6");
    ClapTrap clapTrap7("7");
    clapTrap7 = clapTrap6;
    clapTrap7.attack("yet another target");

    return 0;
}
