#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm 
{
	protected:
		std::string const name;
		bool	sign;
		const int	toSign;
		const int	toExec;
	
	public:
		AForm();
		AForm(std::string name, bool sign, const int toSign, const int toExec);
		AForm(const AForm &other);
		AForm& operator=(const AForm& other);
		virtual ~AForm() = 0;

		//Getters
		std::string		getName() const;
		bool	getSign() const;
		int		getToSign() const;
		int		getToExec() const;


		// Member Function
		void	beSigned(Bureaucrat &b);

		//Exception as well
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};




};

// OVerload (<<)
std::ostream& operator<<(std::ostream& os, const AForm& f);


#endif
