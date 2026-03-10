#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : _target("John Doe"), _name("ShrubberyCreationForm") , _gradeToSign(145), _gradeToExe(137) {}


ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : _target(target), _name("ShrubberyCreationForm") ,_gradeToSign(145), _gradeToExe(137){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) :  _target("John Doe"), _name("ShrubberyCreationForm"), _gradeToSign(145), _gradeToExe(137)  {
	*this = copy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs){
	if (this != &rhs)
	{
		this->_target = rhs._target;
		setSigned(rhs._signed);
	}
	return *this;
}

bool	ShrubberyCreationForm::getSigned() const {
	return (this->_signed);
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

void	ShrubberyCreationForm::setSigned(bool signe)
{
	this->_signed = signe;
}

void	ShrubberyCreationForm::beSigned(Bureaucrat& bureaucrat){
	if (bureaucrat.getGrade() <= this->_gradeToSign)
	{
		std::cout << "lala\n";
		this->_signed = true;
		std::cout << bureaucrat.getName() << " signed " << this->getName() << std::endl;
	}
	else
		throw GradeTooLowException();
}

void	ShrubberyCreationForm::execute(Bureaucrat const & bureaucrat) const
{
	if (!this->_signed)
	{
		throw NotSigned();
	}
	if (bureaucrat.getGrade() < this->_gradeToExe)
	{
		std::string filename = this->_target + "_shrubbery";
		std::ofstream file(filename.c_str());
		file << "              &&& &&  & &&\n          && &*/&*|& ()|/ @, &&\n          &**/(/&/&||/& /_/)_&/_&\n      &_*_&&_* |& |&&/&__%_/_& &&\n     &&   && & &| &| /& & % ()& /&&\n     ()&_---()&*&*|&&-&&--%---()~\n         &&     *|||\n                 |||\n                 |||\n                 |||\n            , -=-~  .-^- _" << std::endl;
		std::cout << bureaucrat.getName() << " executed " << _name << std::endl;
		file.close();
	}
	else
		throw GradeTooLowException();

}

ShrubberyCreationForm::~ShrubberyCreationForm(){}