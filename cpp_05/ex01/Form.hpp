#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form 
{
	private:
		std::string const name;
		bool	sign;
		const int	toSign;
		const int	toExec;
	
	public:
		Form();
		Form(std::string name, bool sign, const int toSign, const int toExec);
		Form(const Form &other);
		Form& operator=(const Form& other);
		~Form();

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
std::ostream& operator<<(std::ostream& os, const Form& f);


#endif
