#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <exception>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class PresidentPardonForm : AForm {
private:
	std::string const _name;
	bool _signe;
	int const _gradeToSign;
	int const _gradeToExe;
public:
	PresidentPardonForm();
	PresidentPardonForm(const PresidentPardonForm& );
	PresidentPardonForm& operator=();
	virtual ~PresidentPardonForm();
};