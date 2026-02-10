#ifndef SHRUBBERYCREACTIONFORM_HPP
#define SHRUBBERYCREACTIONFORM_HPP

#include <iostream>
#include <exception>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : AForm {
private:
	std::string const	_name;
	bool				_signe;
	int const			_gradeToSign;
	int const			_gradeToExe;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& );
	ShrubberyCreationForm& operator=(ShrubberyCreationForm& );


	void	beautifulTree(Bureaucrat& );
	virtual ~ShrubberyCreationForm();
};