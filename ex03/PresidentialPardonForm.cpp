#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm"), _target("John Doe"), _gradeToSign(25), _gradeToExe(5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm"), _target(target), _gradeToSign(25), _gradeToExe(5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm("PresidentialPardonForm"), _target("John Doe"), _gradeToSign(25), _gradeToExe(5) {
	*this = copy;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs){
	if (this != &rhs)
	{
		this->_target = rhs._target;
		setSigned(rhs._signed);
	}
	return *this;
}

bool	PresidentialPardonForm::getSigned() const {
	return (this->_signed);
}

int	PresidentialPardonForm::getGradeExe() const{
	return (this->_gradeToExe);
}

int	PresidentialPardonForm::getGradeSign() const {
	return (this->_gradeToSign);
}

void	PresidentialPardonForm::setSigned(bool signe)
{
	this->_signed = signe;
}

std::string	const	PresidentialPardonForm::getName() const{
	return (this->_name);
}

void	PresidentialPardonForm::beSigned(Bureaucrat& bureaucrat){
	if (bureaucrat.getGrade() <= this->_gradeToSign && getSigned())
	{
		std::cout << bureaucrat.getName() << " signed " << this->getName() << std::endl;
		setSigned(true);
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

