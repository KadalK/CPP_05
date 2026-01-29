#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string& ) {}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) {}

int	Bureaucrat::getGrade() const {
	return (this->_grade);
}

void	Bureaucrat::setGrade(int grade) {
	this->_grade = grade;
}

std::string	const	Bureaucrat::getName() const {
	return (this->_name);
}

void	Bureaucrat::setName(std::string name){
	this->_name = name;
}

void	Bureaucrat::gradeUp(){}
void	Bureaucrat::gradeDown(){}

const char* Bureaucrat::GradeTooHighException::what() const noexcept {
	return "You are aldready PDG"
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept {
return "Have dreams pls"
}

virtual Bureaucrat::~Bureaucrat(){}