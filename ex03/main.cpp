#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"


int main()
{
	Bureaucrat	*pingouin = new Bureaucrat("pingouin");
	Intern		randIntern;
	AForm		*form;

	srand(time(0));

	try
	{
		pingouin->setGrade(5);
		form = randIntern.makeForm("robotomy request", "Sarah Connor");
		std::cout << *pingouin << std::endl;
		std::cout << *form << std::endl;
		pingouin->signAForm(form);
		form->execute(*pingouin);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
		delete pingouin;
		delete form;
}



