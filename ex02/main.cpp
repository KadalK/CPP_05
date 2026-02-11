#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"


int main()
{
	srand(time(0));
	AForm *tree = new ShrubberyCreationForm();
	AForm *robot = new RobotomyRequestForm();
	AForm *prez = new PresidentialPardonForm();
	Bureaucrat *lol = NULL;


	try
	{
		lol = new Bureaucrat("lol");
		lol->setGrade(1);
		std::cout << *lol << std::endl;
		std::cout << *tree << std::endl;
		lol->signAForm(tree);
		tree->executeAction(*lol);
		robot->executeAction(*lol);
		prez->executeAction(*lol);
	}
	catch(std::exception &kk)
	{
		std::cout << kk.what() << std::endl;
	}
		delete lol;
		delete robot;
		delete tree;
}



