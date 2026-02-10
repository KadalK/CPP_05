#include "Bureaucrat.hpp"
#include "AForm.hpp"


int main()
{
	Bureaucrat *lol = new Bureaucrat;
	lol->setGrade(55);
	AForm Formol("Files" ,66, 11);

	try
	{
		std::cout << *lol << std::endl;
		std::cout << Formol << std::endl;
		lol->signAForm(Formol);
	}
	catch(std::exception &kk)
	{
		std::cout << kk.what() << std::endl;
		delete lol;
	}
}


