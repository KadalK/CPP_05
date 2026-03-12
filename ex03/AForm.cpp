#include "AForm.hpp"

AForm::AForm() : _name("AForm"), _sign(false), _gradeToSign(150), _gradeToExe(150) {}
AForm::AForm(std::string name) : _name(name), _sign(false), _gradeToSign(150), _gradeToExe(150)  {}
AForm::AForm(const AForm& copy) : _name(copy._name), _sign(false), _gradeToSign(copy._gradeToSign), _gradeToExe(copy._gradeToExe) {}
AForm::AForm(std::string const name, int const gradeToSing, int const gradeToExe) : _name(name), _sign(false), _gradeToSign(gradeToSing), _gradeToExe(gradeToExe) {
	if (gradeToSing > 150 || gradeToExe > 150)
		throw GradeTooLowException();
	if (gradeToSing < 0 || gradeToExe < 0)
		throw GradeTooHighException();
}

AForm& AForm::operator=(const AForm& rhs){
	if (this != &rhs)
		this->_sign = rhs._sign;
	return *this;
}

int  AForm::getGradeExe() const{
	return (this->_gradeToExe);
}

int	 AForm::getGradeSign() const {
	return (this->_gradeToSign);
}

std::string	const	AForm::getName() const{
	return (this->_name);
}

bool	AForm::getSigned() const{
	return (this->_sign);
}

void	AForm::setSign(bool sign)
{
	this->_sign = sign;
}

void	AForm::beSigned(Bureaucrat& bureaucrat){
	if (bureaucrat.getGrade() <= this->_gradeToSign)
	{
		this->_sign = true;
		std::cout << bureaucrat.getName() << " signed " << this->getName() << std::endl;
	}
	else
		throw GradeTooLowException();
}

const char *AForm::NotSigned::what() const throw() {
	return ("Form not signed");
}

const char *AForm::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}

std::ostream& operator<<(std::ostream &o, AForm& rhs)
{
	o << "This Form is : " << rhs.getName() << "\nGrade of signe : " << rhs.getGradeSign() << "\nGrade of execute : " << rhs.getGradeExe();
	return o;
}

AForm::~AForm(){}
