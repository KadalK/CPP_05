#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <exception>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class Bureaucrat;

class RobotomyRequestForm : public AForm {
private:
	std::string		_target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string );
	RobotomyRequestForm(const RobotomyRequestForm& );
	RobotomyRequestForm& operator=(const RobotomyRequestForm& );

	void	execute(Bureaucrat const & ) const;

	virtual ~RobotomyRequestForm();
};

#endif
