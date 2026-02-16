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

void	FragTrap::attack(std::string const &target)
{
	if (this->EnergyPoints <= 0)
	{
		std::cout <<" FragTrap " << this->name <<" has no energy..." << std::endl;
		return;
	}
	std::cout << "FragTrap " << this->name << " attacks " << target << " with some fraggyyy moveee... CAUSING " << this->AttackDamage << " points of DAMAGE.." << std::endl;
	this->EnergyPoints -= 1;

}

void FragTrap::takeDamage(unsigned int amount)
{
	if (this->HitPoints <= amount)
	{
		std::cout << "FragTrap " << this->name << " is no more with US :(" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->name << " takes " << amount << " Damage!!ahhhh" << std::endl;
	this->HitPoints -= amount;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (this->EnergyPoints <= 0)
	{
		std::cout << "FragTrap " << this->name << " Can't get repaired.. Need more energy!!!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->name << " has just gotten repaired for " << amount << " hit points..." << std::endl;
	EnergyPoints -= 1;
	HitPoints += amount;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " request to High-Five everyone " << std::endl;
}

