#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) , _signe(false) {}


:ShrubberyCreationForm(const ShrubberyCreationForm& copy) : _name(copy._name), _signe(false), _gradeToSign(copy._gradeToSign), _gradeToExe(copy._gradeToExe) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& rhs){
	if (this != &rhs)
		this->_signe = rhs._signe;
	return *this;
}

void	ShrubberyCreationForm::beautifulTree(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() < this->_gradeToExe && bureaucrat.getGrade() < this->_gradeToSign)
		std::cout << "              &&& &&  & &&\n          && &*/&*|& ()|/ @, &&\n          &**/(/&/&||/& /_/)_&/_&\n      &_*_&&_* |& |&&/&__%_/_& &&\n     &&   && & &| &| /& & % ()& /&&\n     ()&_---()&*&*|&&-&&--%---()~\n         &&     *|||\n                 |||\n                 |||\n                 |||\n            , -=-~  .-^- _";
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}