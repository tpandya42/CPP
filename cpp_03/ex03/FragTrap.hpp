#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	private:
		FragTrap();
	
	public:
		FragTrap(std::string name);
		~FragTrap();
		void	highFivesGuys(void);
};


#endif
