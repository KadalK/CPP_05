#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"


int main()
{
	Bureaucrat	*lol = new Bureaucrat("lol");
	Intern		randIntern;
	AForm		*form;

	srand(time(0));

	try
	{
		lol->setGrade(1);
		form = randIntern.makeForm("robotomy requt", "kaka");
		std::cout << *lol << std::endl;
		std::cout << *form << std::endl;
		lol->signAForm(form);
		form->executeAction(*lol);
	}
	catch(std::exception &kk)
	{
		std::cout << kk.what() << std::endl;
	}
		delete lol;
		delete form;
}



