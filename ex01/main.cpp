#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <cstddef>


int main()
{
	Bureaucrat *lol = NULL;
	Form *Formol = NULL;

	try
	{
		lol = new Bureaucrat;
		lol->setGrade(55);
		Formol =  new Form(-66);
		std::cout << *lol << std::endl;
		std::cout << *Formol << std::endl;
		lol->signForm(*Formol);
	}
	catch(std::exception &kk)
	{
		std::cout << kk.what() << std::endl;
	}
	delete lol;
	delete Formol;
}


