#include "Form.hpp"

Form::Form() : _name("administrativ shit"), _signe(false), _gradeToSign(1), _gradeToExe(1) {
}

Form::Form(const Form& copy) : _name(copy._name), _signe(false), _gradeToSign(copy._gradeToSign), _gradeToExe(copy._gradeToExe) {} //fix that shit

Form& Form::operator=(Form& rhs){  //fix that shit
	if (this != &rhs)
	{
		this->_signe = rhs._signe;
//		this->_name = rhs._name;
//		this->_gradeToSign = rhs._gradeToSign;
//		this->_gradeToExe = rhs._gradeToExe;
	}
	return *this;
}

int	Form::getGradeExe() const{
	return (this->_gradeToExe);
}

//void	Form::setGradeExe(int grade){
//	this->_gradeToExe = grade;
//}

int	Form::getGradeSign() const{
	return (this->_gradeToSign);
}

//void	Form::setGradeSign(int grade){
//	this->_gradeToSign = grade;
//}

std::string	const	Form::getName() const{
	return (this->_name);
}

//void	Form::gradeUp(){
//	if (this->_gradeToExe <= 1)
//		throw GradeTooHighException();
//	int tmp = this->_gradeToExe;
//	tmp--;
//	this->_gradeToExe = tmp;
//}

//void	Form::gradeDown(){
//	if (this->_gradeToExe >= 150)
//		throw GradeTooLowException();
//	int tmp = this->_gradeToExe;
//	tmp++;
//	this->_gradeToExe = tmp;
//}

void	Form::beSigned(Bureaucrat bureaucrat){
	if (bureaucrat.getGrade() <= this->_gradeToSign)
	{
		std::cout << bureaucrat.getName() << " signed " << this->getName() <<  std::endl;
		this->_signe = true;
	}
	else
	{
		throw GradeTooLowException();
	}
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("You are the boss, dont do the dirty work");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("This form does not concern you, mouve around");
}

std::ostream& operator<<(std::ostream &o, Form& rhs)
{
	o << "This form is : " << rhs.getName() << "\nGrade of signe : " << rhs.getGradeSign() << "\nGrade of execute : " << rhs.getGradeExe();
	return o;
}

Form::~Form(){}
