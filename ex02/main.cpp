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
		lol->setGrade(150);
		lol->gradeDown();
		std::cout << *lol << std::endl;
		std::cout << *tree << std::endl;
		lol->signAForm(tree);
		tree->execute(*lol);
		robot->execute(*lol);
		prez->execute(*lol);
	}
	catch(std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
		delete lol;
		delete robot;
		delete tree;
		delete prez;
}



