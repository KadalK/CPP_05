#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <exception>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm {
private:
	std::string		_target;
	std::string		_name;
	bool			_signed;
	int	const		_gradeToSign;
	int	const		_gradeToExe;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string );
	PresidentialPardonForm(const PresidentialPardonForm& );
	PresidentialPardonForm& operator=(const PresidentialPardonForm& );

	bool				getSigned() const;
	int					getGradeExe() const;
	int 				getGradeSign() const;
	std::string	const	getName() const;

	void	setSigned(bool );

	void	beSigned(Bureaucrat& );
	void	executeAction(Bureaucrat& );

	virtual ~PresidentialPardonForm();
};

#endif