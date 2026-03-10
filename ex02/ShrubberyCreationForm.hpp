#ifndef SHRUBBERYCREACTIONFORM_HPP
#define SHRUBBERYCREACTIONFORM_HPP

#include <iostream>
#include <exception>
#include <string>
#include <fstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
private:
	std::string		_target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string );
	ShrubberyCreationForm(const ShrubberyCreationForm& );
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& );

	void	execute(Bureaucrat const & ) const;

	virtual ~ShrubberyCreationForm();
};

#endif