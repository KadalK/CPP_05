#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <exception>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat {
private:
	std::string	const	_name;
	int					_grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string& );
	Bureaucrat(const Bureaucrat& );
	Bureaucrat &operator=(const Bureaucrat& );

	int					getGrade() const;
	void				setGrade(int );
	std::string	const	getName() const;

	void	gradeUp();
	void	gradeDown();
	void	signForm(Form );

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