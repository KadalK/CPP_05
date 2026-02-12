#include "Form.hpp"

Form::Form() : _name("administrative shit"), _signe(false), _gradeToSign(150), _gradeToExe(150) {}

Form::Form(const Form& copy) : _name(copy._name), _signe(false), _gradeToSign(copy._gradeToSign), _gradeToExe(copy._gradeToExe) {}

Form::Form(int const grade) : _name("administrative shit"), _gradeToSign(grade), _gradeToExe(150) {
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException() ;
}

Form& Form::operator=(const Form& rhs){
	if (this != &rhs)
		this->_signe = rhs._signe;
	return *this;
}

int	Form::getGradeExe() const{
	return (this->_gradeToExe);
}

int	Form::getGradeSign() const {
	return (this->_gradeToSign);
}

std::string	const	Form::getName() const{
	return (this->_name);
}

void	Form::beSigned(Bureaucrat bureaucrat){
	if (bureaucrat.getGrade() <= this->_gradeToSign)
	{
		std::cout << bureaucrat.getName() << " signed " << this->getName() << std::endl;
		this->_signe = true;
	}
	else
		throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("Grade to high");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Grade to low");
}

std::ostream& operator<<(std::ostream &o, Form& rhs)
{
	o << "This Form is : " << rhs.getName() << "\nGrade of signe : " << rhs.getGradeSign() << "\nGrade of execute : " << rhs.getGradeExe();
	return o;
}

Form::~Form(){}
