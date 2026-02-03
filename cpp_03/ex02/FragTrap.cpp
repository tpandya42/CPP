#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->HitPoints = 100;
	this->EnergyPoints = 100;
	this->AttackDamage= 30;
	std::cout << "FragTrap " << this->name << "'s" << " Constructor Called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->name << " has been destroyed  " << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap " << this->name << " copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &src)
{
	ClapTrap::operator=(src);
	std::cout << "FragTrap " << this->name << " copy assignment operator called" << std::endl;
	return *this;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " request to High-Five everyone " << std::endl;
}

