#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
	private:
		std::string	name;
		int	HitPoints = 10;
		int	EnergyPoints = 10;
		int	AttackDamage = 0;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beReparied(unsigned int amount);
};


#endif
