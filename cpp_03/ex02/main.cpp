#include "FragTrap.hpp"

int main(void)
{
    FragTrap fragTrap("FT-1");

    fragTrap.attack("some target");
    fragTrap.takeDamage(5);
    fragTrap.beRepaired(3);
    fragTrap.highFivesGuys();

    std::cout << "--------------------" << std::endl;

    FragTrap fragTrap2("FT-2");
    fragTrap2.takeDamage(99);
    fragTrap2.takeDamage(1);

    std::cout << "--------------------" << std::endl;

    FragTrap fragTrap3("FT-3");
    for (int i = 0; i < 101; i++)
        fragTrap3.attack("some other target");
    
    std::cout << "--------------------" << std::endl;

    FragTrap fragTrap4("FT-4");
    FragTrap fragTrap5(fragTrap4);
    fragTrap5.attack("another target");

    std::cout << "--------------------" << std::endl;

    FragTrap fragTrap6("FT-6");
    FragTrap fragTrap7("FT-7");
    fragTrap7 = fragTrap6;
    fragTrap7.attack("yet another target");

    return 0;
}