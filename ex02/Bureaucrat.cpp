#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Mr.Smith"){}

Bureaucrat::Bureaucrat(const std::string& name) : _name(name) {}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs){
	if (this != &rhs)
	{
		this->_grade = rhs._grade;
	}
	return *this;
}

int	Bureaucrat::getGrade() const {
	return (this->_grade);
}

void	Bureaucrat::setGrade(int grade) {
	this->_grade = grade;
}

std::string	const	Bureaucrat::getName() const {
	return (this->_name);
}


void	Bureaucrat::gradeUp(){

	if (this->_grade <= 1)
		throw GradeTooHighException();
	int tmp = this->_grade;
	tmp--;
	this->_grade = tmp;
}

void	Bureaucrat::gradeDown(){
	if (this->_grade >= 150)
	{
		throw GradeTooLowException();
	}
	int tmp = this->_grade;
	tmp++;
	this->_grade = tmp;
}

void	Bureaucrat::signAForm(AForm *AForm){
	std::string	reason = "you stink";
	if (this->getGrade() > AForm->getGradeSign())
	{
		if ( this->_grade - AForm->getGradeSign() == 1)
		{
			reason = "it's the role of your superior";
		}
		if (this->_grade - AForm->getGradeSign() == 2)
			reason = "You are not qualified for that !";
	}
	if (this->_grade <= AForm->getGradeSign())
		AForm->beSigned(*this);
	else
		std::cout << this->_name << " couldn’t sign " << AForm->getName() << " because " << reason <<std::endl;
}

std::ostream& operator<<(std::ostream &o, Bureaucrat& rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return o;
}


const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade to hight");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade to low");
}

Bureaucrat::~Bureaucrat(){}