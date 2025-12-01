#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>

class PhoneBook
{
	private:
		Contact contacts[8];
		int	_index;
		bool	_isFull;

	public:
		PhoneBook();
		~PhoneBook();

		void	add();
		void	search();

};

#endif
