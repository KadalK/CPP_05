#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <exception>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
private:
	std::string	const	_name;
	int					_grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string& );
	Bureaucrat(const Bureaucrat& );
	Bureaucrat(const std::string& , int );
	Bureaucrat &operator=(const Bureaucrat& );

	void				setGrade(int );
	int					getGrade() const;
	std::string	const	getName() const;

	void	gradeUp();
	void	gradeDown();
	void	signForm(AForm* );
	void	executeForm(AForm const & form) const;

	class GradeTooHighException : public std::exception {
		virtual const char* what() const throw();
	};

	class GradeTooLowException :  public std::exception {
		virtual const char* what() const throw();
	};

	virtual ~Bureaucrat();
};

std::ostream& operator<<(std::ostream& o, Bureaucrat& rhs);


#endif