#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("John Doe") {}
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm("RobotomyRequestForm", 72, 45), _target("John Doe") {
	*this = copy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs){
	if (this != &rhs)
	{
		this->_target = rhs._target;
		setSign(rhs.getSigned());
	}
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const & bureaucrat) const
{
	if (!getSigned())
		throw NotSigned();

	if (bureaucrat.getGrade() < getGradeExe())
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
