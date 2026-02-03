#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap clapTrap("CT-1");

    clapTrap.attack("some target");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(3);
    clapTrap.takeDamage(10);
    clapTrap.beRepaired(5);
    clapTrap.attack("another target");

    std::cout << "--------------------" << std::endl;

    ClapTrap clapTrap2("CT-2");
    clapTrap2.takeDamage(9);
    clapTrap2.takeDamage(1);

    std::cout << "--------------------" << std::endl;

    ClapTrap clapTrap3("CT-3");
    for (int i = 0; i < 11; i++)
        clapTrap3.attack("some other target");

    std::cout << "--------------------" << std::endl;
    
    ClapTrap clapTrap4("CT-4");
    ClapTrap clapTrap5(clapTrap4);
    clapTrap5.attack("another target");

    std::cout << "--------------------" << std::endl;

    ClapTrap clapTrap6("CT-6");
    ClapTrap clapTrap7("CT-7");
    clapTrap7 = clapTrap6;
    clapTrap7.attack("yet another target");

    return 0;
}