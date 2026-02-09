#include "Bureaucrat.hpp"
#include "Form.hpp"


int main()
{
	Bureaucrat *lol = new Bureaucrat;
	lol->setGrade(55);
	Form formol(66);

	try
	{
		std::cout << *lol << std::endl;
		std::cout << formol << std::endl;
		lol->signForm(formol);
	}
	catch(std::exception &kk)
	{
		std::cout << kk.what() << std::endl;
		delete lol;
	}
}


