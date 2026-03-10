#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm"), _target("John Doe"), _name("RobotomyRequestForm"), _gradeToSign(145), _gradeToExe(137) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm"), _target(target), _name("RobotomyRequestForm"), _gradeToSign(145), _gradeToExe(137) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm("RobotomyRequestForm"), _target("John Doe"), _name("RobotomyRequestForm"), _gradeToSign(145), _gradeToExe(137) {
	*this = copy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs){
	if (this != &rhs)
	{
		this->_target = rhs._target;
		setSigned(rhs._signed);
	}
	return *this;
}

int	RobotomyRequestForm::getGradeExe() const{
	return (this->_gradeToExe);
}

int	RobotomyRequestForm::getGradeSign() const {
	return (this->_gradeToSign);
}

std::string	const	RobotomyRequestForm::getName() const{
	return (this->_name);
}

void	RobotomyRequestForm::setSigned(bool signe)
{
	this->_signed = signe;
}

void	RobotomyRequestForm::beSigned(Bureaucrat& bureaucrat){
	if (bureaucrat.getGrade() <= this->_gradeToSign)
	{
		std::cout << bureaucrat.getName() << " signed " << this->getName() << std::endl;
		setSigned(true);
	}
	else
		throw GradeTooLowException();
}


void	RobotomyRequestForm::execute(Bureaucrat const & bureaucrat) const
{
	if (!this->_signed)
		throw NotSigned();

	if (bureaucrat.getGrade() < this->_gradeToExe)
	{
		std::cout << " *drill noise* " << std::endl;
		std::cout << " . " << std::endl;
		sleep(1);
		std::cout << " . " << std::endl;
		sleep(1);
		std::cout << " . " << std::endl;
		sleep(1);
		if (rand() % 2)
			std::cout << "**"<< this->_target << " aAs *beep* b3en rob0tomiZZZed**"  << std::endl;
		else
			std::cout <<  " **tHe pR roC3SS hAve f4IlEd** " << std::endl;
	}

}

RobotomyRequestForm::~RobotomyRequestForm(){}