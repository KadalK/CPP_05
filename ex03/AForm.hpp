#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include <exception>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
	std::string	const	_name;
	bool				_signe;
	int const			_gradeToSign;
	int const			_gradeToExe;
public:
	AForm();
	AForm(const AForm& );
	AForm(std::string const , int const , int const);
	AForm(std::string const );
	AForm &operator=(const AForm& );

	int					getGradeExe() const;
	int 				getGradeSign() const;
	std::string	const	getName() const;

	virtual void	beSigned(Bureaucrat& );
	virtual void	executeAction(Bureaucrat& ) = 0;
	void			execute(Bureaucrat& );

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