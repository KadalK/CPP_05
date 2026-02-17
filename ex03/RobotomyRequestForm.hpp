#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <exception>
#include <string>
#include <iostream>
#include "time.h"
#include "stdio.h"
#include <unistd.h>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <cstdlib>

class Bureaucrat;

class RobotomyRequestForm : public AForm {
private:
	std::string		_target;
	std::string		_name;
	bool			_signed;
	int	const		_gradeToSign;
	int	const		_gradeToExe;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string );
	RobotomyRequestForm(const RobotomyRequestForm& );
	RobotomyRequestForm& operator=(const RobotomyRequestForm& );

	int					getGradeExe() const;
	int 				getGradeSign() const;
	std::string	const	getName() const;

	void setSigned(bool );

	void	beSigned(Bureaucrat& );
	void	execute(Bureaucrat const & ) const;

	virtual ~RobotomyRequestForm();
};

#endif