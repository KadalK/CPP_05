#include "AForm.hpp"

AForm::AForm() : _name("administrative shit"), _signe(false), _gradeToSign(150), _gradeToExe(150) {}

AForm::AForm(const AForm& copy) : _name(copy._name), _signe(false), _gradeToSign(copy._gradeToSign), _gradeToExe(copy._gradeToExe) {}

AForm::AForm(std::string const name, int const gradeToSing, int const gradeToExe) : _name(name), _gradeToSign(gradeToSing), _gradeToExe(gradeToExe) , _signe(false) {}

AForm& AForm::operator=(AForm& rhs){
	if (this != &rhs)
		this->_signe = rhs._signe;
	return *this;
}

int	AForm::getGradeExe() const{
	return (this->_gradeToExe);
}

int	AForm::getGradeSign() const {
	return (this->_gradeToSign);
}

std::string	const	AForm::getName() const{
	return (this->_name);
}

void	AForm::beSigned(Bureaucrat bureaucrat){
	if (bureaucrat.getGrade() <= this->_gradeToSign)
	{
		std::cout << bureaucrat.getName() << " signed " << this->getName() << std::endl;
		this->_signe = true;
	}
	else
		throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw() {
	return ("You are the boss, dont do the dirty work");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("This AForm does not concern you, mouve around");
}

std::ostream& operator<<(std::ostream &o, AForm& rhs)
{
	o << "This AForm is : " << rhs.getName() << "\nGrade of signe : " << rhs.getGradeSign() << "\nGrade of execute : " << rhs.getGradeExe();
	return o;
}

AForm::~AForm(){}
