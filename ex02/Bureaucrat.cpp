#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Mr.Smith"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name) : _name(name), _grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
	setGrade(grade);
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs){
	if (this != &rhs)
		this->_grade = rhs._grade;
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

void	Bureaucrat::signAForm(AForm &AForm){


	try {
		AForm.beSigned(*this);
	} catch (std::exception &e) {
		std::cout << this->_name << " couldn’t sign " << AForm.getName() << " because " << e.what() <<std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &form) const
{
	try {
		form.execute(*this);
	} catch (std::exception &e) {
		std::cout << this->_name << " couldn’t sign " << form.getName() << " because " << e.what() <<std::endl;
	}
}


std::ostream& operator<<(std::ostream &o, Bureaucrat& rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return o;
}


const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}

Bureaucrat::~Bureaucrat(){}