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
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string );
	PresidentialPardonForm(const PresidentialPardonForm& );
	PresidentialPardonForm& operator=(const PresidentialPardonForm& );

	void	execute(Bureaucrat const & ) const;

	virtual ~PresidentialPardonForm();
};

#endif