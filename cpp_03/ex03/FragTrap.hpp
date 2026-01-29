#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
		FragTrap();
	
	public:
		FragTrap(std::string name);
		~FragTrap();
		void	highFivesGuys(void);
};


#endif
