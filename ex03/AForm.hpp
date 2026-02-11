#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
protected:
	std::string	const	_name;
	bool				_signe;
	int const			_gradeToSign;
	int const			_gradeToExe;
public:
	AForm();
	AForm(const AForm& );
	AForm(std::string const , int const , int const);
	AForm &operator=(const AForm& );

	virtual int					getGradeExe() const;
	virtual int 				getGradeSign() const;
	virtual std::string	const	getName() const;

	virtual void	beSigned(Bureaucrat& );
	void			execute(Bureaucrat& );
	virtual void	executeAction(Bureaucrat& ) = 0;

class	NotSignedException : public std::exception {
		virtual const char* what() const throw();
};

	class GradeTooHighException : public std::exception {
		virtual const char* what() const throw();
	};

	class GradeTooLowException :  public std::exception {
		virtual const char* what() const throw();
	};

	virtual ~AForm();
};

std::ostream& operator<<(std::ostream& o, AForm& rhs);

#endif