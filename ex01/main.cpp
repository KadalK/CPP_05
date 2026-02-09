#include "Bureaucrat.hpp"
#include "Form.hpp"


int main()
{
	Form *formol = new Form;
	Bureaucrat *lol = new Bureaucrat;

	lol->setGrade(5);
	try
	{
		std::cout << *lol << std::endl;
		lol->signForm(*formol);
		std::cout << *formol << std::endl;
	}
	catch(std::exception &kk)
	{
		std::cout << kk.what() << std::endl;
		delete lol;
		delete formol;
	}
}


