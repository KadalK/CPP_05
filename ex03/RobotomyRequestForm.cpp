#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("John Doe") {}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm("RobotomyRequestForm", 72, 45), _target("John Doe") {
	*this = copy;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45) , _target(target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs){
	if (this != &rhs)
	{
		this->_target = rhs._target;
		this->_signe = rhs._signe;
	}
	return *this;
}

int	RobotomyRequestForm::getGradeExe() const{
	return (this->_gradeToExe);
}

int	RobotomyRequestForm::getGradeSign() const {
	return (this->_gradeToSign);
}

std::string	const	RobotomyRequestForm::getName() const{
	return (this->_name);
}

void	RobotomyRequestForm::beSigned(Bureaucrat& bureaucrat){
	if (bureaucrat.getGrade() <= this->_gradeToSign)
	{
		std::cout << bureaucrat.getName() << " signed " << this->getName() << std::endl;
		this->_signe = true;
	}
	else
		throw GradeTooLowException();
}

void	RobotomyRequestForm::executeAction(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() < this->_gradeToExe)
	{
		std::cout << " *drill noise* " << std::endl;
		std::cout << " . " << std::endl;
		sleep(1);
		std::cout << " . " << std::endl;
		sleep(1);
		std::cout << " . " << std::endl;
		sleep(1);
		if (rand() % 2)
			std::cout << "**"<< this->_target << " aAs *beep* b3en rob0tomiZZZed**"  << std::endl;
		else
			std::cout <<  " **tHe pR roC3SS hAve f4IlEd** " << std::endl;
	}

}

RobotomyRequestForm::~RobotomyRequestForm(){}