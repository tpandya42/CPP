#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage= 20;
	std::cout << "ScavTrap " << this->name << " is constructed...." << std::endl;
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

void	ScavTrap::gaurdGate()
{
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}
