#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("John Doe") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm("PresidentialPardonForm", 145, 137), _target("John Doe"){
	*this = copy;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs){
	if (this != &rhs)
	{
		this->_target = rhs._target;
		this->_signe = rhs._signe;
	}
	return *this;
}


int	PresidentialPardonForm::getGradeExe() const{
	return (this->_gradeToExe);
}

int	PresidentialPardonForm::getGradeSign() const {
	return (this->_gradeToSign);
}

std::string	const	PresidentialPardonForm::getName() const{
	return (this->_name);
}

void	PresidentialPardonForm::beSigned(Bureaucrat& bureaucrat){
	if (bureaucrat.getGrade() <= this->_gradeToSign)
	{
		std::cout << bureaucrat.getName() << " signed " << this->getName() << std::endl;
		this->_signe = true;
	}
	else
		throw GradeTooLowException();
}

void	PresidentialPardonForm::executeAction(Bureaucrat& bureaucrat){
	if (bureaucrat.getGrade() <= this->_gradeToSign)
		std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	else
		throw GradeTooLowException();
}

PresidentialPardonForm::~PresidentialPardonForm(){}

