#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"


int main()
{
	srand(time(0));
	AForm *tree = NULL;
	AForm *robot = NULL;
	AForm *prez = NULL;
	Bureaucrat *lol = NULL;


	try
	{
		tree = new ShrubberyCreationForm();
		robot = new RobotomyRequestForm();
		prez = new PresidentialPardonForm();
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
		delete prez;
}



