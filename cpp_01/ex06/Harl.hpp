#ifndef HARL_HPP
# define HARL_HPP

#include <string>
#include <iostream>

class Harl {
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
	
	public:
		Harl();
		~Harl();
		void	complain(std::string level);
};

// Just a alias.., functPTR points to a member function of our class HARL.. (returns void, and takes no argument)
typedef void	(Harl::*functPTR)(void);

#endif
