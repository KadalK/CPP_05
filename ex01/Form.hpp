#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
	std::string	const	_name;
	bool				_signe;
	int const			_gradeToSign;
	int const			_gradeToExe;
public:
	Form();
	Form(const Form& );
	Form(int const );
	Form &operator=(Form& );

	int				getGradeExe() const;

	int				getGradeSign() const;

	std::string	const	getName() const;

	void	beSigned(Bureaucrat );

	class GradeTooHighException : public std::exception {
		virtual const char* what() const throw();
	};

	class GradeTooLowException :  public std::exception {
		virtual const char* what() const throw();
	};

	virtual ~Form();
};

std::ostream& operator<<(std::ostream& o, Form& rhs);

#endif