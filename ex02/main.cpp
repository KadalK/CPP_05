#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"


int main()
{
	srand(time(0));
	AForm *tree = NULL;
	Bureaucrat *lol = NULL;


	try
	{
		tree = new RobotomyRequestForm();
		lol = new Bureaucrat("lol");
		lol->setGrade(5);
		std::cout << *lol << std::endl;
		std::cout << *tree << std::endl;
		lol->signAForm(*tree);
		tree->execute(*lol);
	}
	catch(std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
		delete lol;
		delete tree;
}



