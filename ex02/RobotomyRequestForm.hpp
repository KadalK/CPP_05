#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <exception>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : AForm {
private:
	std::string const _name;
	bool _signe;
	int const _gradeToSign;
	int const _gradeToExe;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& );
	RobotomyRequestForm& operator=();
	virtual ~RobotomyRequestForm();
};