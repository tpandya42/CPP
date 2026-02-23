#ifndef FORM_HPP
# define FORM_HPP

#include <exception>
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm 
{
	private:
		std::string const name;
		bool	sign;
		const int	toSign;
				const int	toExec;
		
			protected:
				virtual void exec() const = 0;
			
			public:
		AForm();
		AForm(std::string name, bool sign, const int toSign, const int toExec);
		AForm(const AForm &other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		//Getters
		std::string		getName() const;
		bool	getSign() const;
		int		getToSign() const;
		int		getToExec() const;


		// Member Function
		void	beSigned(Bureaucrat &b);
		void	execute(Bureaucrat const & executor) const;

		//Exception as well
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class FormNotSignedExecption : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

// OVerload (<<)
std::ostream& operator<<(std::ostream& os, const AForm& f);


#endif
