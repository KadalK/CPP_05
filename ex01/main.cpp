#include "Bureaucrat.hpp"
#include "AForm.hpp"


int main()
{
	Bureaucrat *lol = new Bureaucrat;
	lol->setGrade(55);
	AForm AFormol(66);

	try
	{
		std::cout << *lol << std::endl;
		std::cout << AFormol << std::endl;
		lol->signAForm(AFormol);
	}
	catch(std::exception &kk)
	{
		std::cout << kk.what() << std::endl;
		delete lol;
	}
}


