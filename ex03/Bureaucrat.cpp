#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("John Doe"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name) : _name(name), _grade(150) {}

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
	if (grade > 150)
	{
		std::cout << "This (" << grade << ") is unavailable :" << std::endl;
		throw GradeTooLowException();
	}
	if (grade < 1)
	{
		std::cout << "This grade (" << grade << ") is unavailable" << std::endl;
		throw GradeTooHighException();
	}
	this->_grade = grade;
}

std::string	const	Bureaucrat::getName() const {
	return (this->_name);
}


void	Bureaucrat::gradeUp(){

	if (this->_grade <= 1)
		throw GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::gradeDown(){
	if (this->_grade >= 150)
		throw GradeTooLowException();
	this->_grade++;
}

void	Bureaucrat::signAForm(AForm *AForm){
	if (!AForm)
		return;

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
	return ("You are already PDG");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Have dreams pls";
}

Bureaucrat::~Bureaucrat(){}