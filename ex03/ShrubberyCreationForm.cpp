#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("John Doe") {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm("ShrubberyCreationForm", 145, 137), _target("John Doe")  {
	*this = copy;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs){
	if (this != &rhs)
	{
		this->_target = rhs._target;
		this->_signe = rhs._signe;
	}
	return *this;
}


void	ShrubberyCreationForm::executeAction(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() < this->_gradeToExe && this->_signe)
	{
		std::string filename = this->_target + "_shrubbery";
		std::ofstream file(filename.c_str());
		file << "              &&& &&  & &&\n          && &*/&*|& ()|/ @, &&\n          &**/(/&/&||/& /_/)_&/_&\n      &_*_&&_* |& |&&/&__%_/_& &&\n     &&   && & &| &| /& & % ()& /&&\n     ()&_---()&*&*|&&-&&--%---()~\n         &&     *|||\n                 |||\n                 |||\n                 |||\n            , -=-~  .-^- _" << std::endl;
		std::cout << bureaucrat.getName() << " executed " << this->getName() << std::endl;
		file.close();
	}
	else
		throw GradeTooLowException();

}

int	ShrubberyCreationForm::getGradeExe() const{
	return (this->_gradeToExe);
}

int	ShrubberyCreationForm::getGradeSign() const {
	return (this->_gradeToSign);
}

std::string	const	ShrubberyCreationForm::getName() const{
	return (this->_name);
}

void	ShrubberyCreationForm::beSigned(Bureaucrat& bureaucrat){
	if (bureaucrat.getGrade() <= this->_gradeToSign)
	{
		std::cout << bureaucrat.getName() << " signed " << this->getName() << std::endl;
		this->_signe = true;
	}
	else
		throw GradeTooLowException();
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}