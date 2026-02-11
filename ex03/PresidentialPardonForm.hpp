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
	std::string	_target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& );
	PresidentialPardonForm(const std::string );
	PresidentialPardonForm& operator=(const PresidentialPardonForm& );

	int					getGradeExe() const;
	int 				getGradeSign() const;
	std::string	const	getName() const;

	void	beSigned(Bureaucrat& );
	void	executeAction(Bureaucrat& );
	virtual ~PresidentialPardonForm();
};

#endif