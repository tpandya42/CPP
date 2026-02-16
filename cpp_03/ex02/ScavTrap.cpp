#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage= 20;
	std::cout << "ScavTrap " << this->name << " is constructed...." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap " << this->name << " copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &src)
{
	ClapTrap::operator=(src);
	std::cout << "ScavTrap " << this->name << " copy assignment operator called" << std::endl;
	return *this;
}


ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->name <<" has been destroyed... " << std::endl;
}

void ScavTrap::attack(std::string const& target)
{
	if (this->EnergyPoints <= 0)
	{
		std::cout <<" ScavTrap " << this->name <<" has no energy..." << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->name << " attacks " << target << " with crazy power... CAUSING " << this->AttackDamage << " points of DAMAGE.." << std::endl;
	this->EnergyPoints -= 1;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (this->HitPoints <= amount)
	{
		std::cout << "ScavTrap " << this->name << " is no more with US :(" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->name << " takes " << amount << " Damage!!ahhhh" << std::endl;
	this->HitPoints -= amount;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (this->EnergyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->name << " Can't get repaired.. Need more energy!!!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->name << " has just gotten repaired for " << amount << " hit points..." << std::endl;
	EnergyPoints -= 1;
	HitPoints += amount;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}
