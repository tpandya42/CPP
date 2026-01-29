#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap (name), FragTrap(name), ScavTrap(name)
{
	this->_name = name;
	this->ClapTrap::name = name + "_clap_name";
	FragTrap::HitPoints= 100;
	ScavTrap::EnergyPoints = 50;
	FragTrap::AttackDamage = 30;
	std::cout << "< DiamondTrap > " << this->_name << " has been construcuted...." << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "< DiamondTrap > " << this->_name << " has been destroyed.... " << std::endl;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "\nDiamondTrap name is: " << this->_name << std::endl << "ClapTrap name is: " << ClapTrap::name << std::endl;
}
