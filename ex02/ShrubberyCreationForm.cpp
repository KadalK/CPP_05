#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("John Doe") {}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm("ShrubberyCreationForm", 145, 137), _target("John Doe") {
	*this = copy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs){
	if (this != &rhs)
	{
		this->_target = rhs._target;
		setSign(rhs.getSigned());
	}
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & bureaucrat) const
{
	if (!getSigned())
	{
		throw NotSigned();
	}
	if (bureaucrat.getGrade() < getGradeExe())
	{
		std::string filename = this->_target + "_shrubbery";
		std::ofstream file(filename.c_str());
		file << "              &&& &&  & &&\n          && &*/&*|& ()|/ @, &&\n          &**/(/&/&||/& /_/)_&/_&\n      &_*_&&_* |& |&&/&__%_/_& &&\n     &&   && & &| &| /& & % ()& /&&\n     ()&_---()&*&*|&&-&&--%---()~\n         &&     *|||\n                 |||\n                 |||\n                 |||\n            , -=-~  .-^- _" << std::endl;
		std::cout << bureaucrat.getName() << " executed " << getName() << std::endl;
		file.close();
	}
	else
		throw GradeTooLowException();

}

ShrubberyCreationForm::~ShrubberyCreationForm(){}