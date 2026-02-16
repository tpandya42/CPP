#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
	FragTrap::HitPoints= 100;
	ScavTrap::EnergyPoints = 50;
	FragTrap::AttackDamage = 30;
	std::cout << "< DiamondTrap > " << this->_name << " has been construcuted...." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), FragTrap(other), ScavTrap(other)
{
	std::cout << "DiamondTrap " << this->_name << " copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &src)
{
	ClapTrap::operator=(src);
	std::cout << "DiamondTrap " << this->_name << " copy assignment operator called" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "< DiamondTrap > " << this->_name << " has been destroyed.... " << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::takeDamage(unsigned int amount)
{
	ScavTrap::takeDamage(amount);
}

void	DiamondTrap::beRepaired(unsigned int amount)
{
	ScavTrap::beRepaired(amount);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "\nDiamondTrap name is: " << this->_name << std::endl << "ClapTrap name is: " << this->name << std::endl;
}
