#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
	: name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
	std::cout << "<ClapTrap> Default Constructor for " << name << " has been called " << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	this->name = other.name;
	this->HitPoints = other.HitPoints;
	this->EnergyPoints = other.EnergyPoints;
	this->AttackDamage = other.AttackDamage;
	std::cout << "<ClapTrap> Copy Constructor has been called " << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &src)
{
	if (this != &src)
	{
		this->name = src.name;
		this->HitPoints = src.HitPoints;
		this->EnergyPoints = src.EnergyPoints;
		this->AttackDamage = src.AttackDamage;
	}
	std::cout << "<ClapTrap> Copy assignment Constructor has been called " << std::endl;
	return *this;
}


ClapTrap::~ClapTrap(void)
{
	std::cout <<"<ClapTrap>  Default Destructor has been called " << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->EnergyPoints <= 0)
	{
		std::cout << this->name << " has no Energy Left!!!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name <<
		" attacks " << target << " causing " << this->AttackDamage << " points of damage!" << std::endl;
	this->EnergyPoints -=1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->HitPoints <= amount)
	{
		std::cout << "ClapTrap " << this->name << " is no more with US :(" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " takes " << amount << " Damage!!ahhhh" << std::endl;
	this->HitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->EnergyPoints <= amount)
	{
		std::cout << "ClapTrap " << this->name << " Can't get repaired.. Need more energy!!!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " has just gotten repaired for " << amount << " hit points..." << std::endl;
	EnergyPoints -= 1;
	HitPoints += amount;
}
