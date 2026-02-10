#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) , _signe(false) {}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : _name(copy._name), _signe(false), _gradeToSign(copy._gradeToSign), _gradeToExe(copy._gradeToExe) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& rhs){
	if (this != &rhs)
		this->_signe = rhs._signe;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){}