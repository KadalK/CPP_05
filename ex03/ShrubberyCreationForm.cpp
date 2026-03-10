#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm"), _target("John Doe"), _name("ShrubberyCreationForm"), _gradeToSign(145), _gradeToExe(137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm"), _target(target), _name("ShrubberyCreationForm"), _gradeToSign(145), _gradeToExe(137){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm("ShrubberyCreationForm"),  _target("John Doe"), _name("ShrubberyCreationForm"),  _gradeToSign(145), _gradeToExe(137)  {
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
		std::cout << bureaucrat.getName() << " signed " << this->getName() << std::endl;
		setSigned(true);
	}
	else
		throw GradeTooLowException();
}

const char *ShrubberyCreationForm::NotPerm::what() const throw() {
	return ("Permission denied");
}

void	ShrubberyCreationForm::execute(Bureaucrat const & bureaucrat) const
{
	if (!this->_signed)
		throw NotSigned();

	if (bureaucrat.getGrade() < this->_gradeToExe)
	{
		std::string filename = this->_target + "_shrubbery";
		std::ofstream file(filename.c_str());
		if (!file.is_open())
			throw NotPerm();
		file << "              &&& &&  & &&\n          && &*/&*|& ()|/ @, &&\n          &**/(/&/&||/& /_/)_&/_&\n      &_*_&&_* |& |&&/&__%_/_& &&\n     &&   && & &| &| /& & % ()& /&&\n     ()&_---()&*&*|&&-&&--%---()~\n         &&     *|||\n                 |||\n                 |||\n                 |||\n            , -=-~  .-^- _" << std::endl;
		std::cout << bureaucrat.getName() << " executed " << this->_name << std::endl;
		file.close();
	}
	else
		throw GradeTooLowException();
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}