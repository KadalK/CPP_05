#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <cstddef>


int main()
{
	Bureaucrat *pingouin = NULL;
	Form *Formol = NULL;

	try
	{
		pingouin = new Bureaucrat("Pin");
		pingouin->setGrade(55);
		Formol =  new Form(66);
		std::cout << *pingouin << std::endl;
		std::cout << *Formol << std::endl;
		pingouin->signForm(*Formol);
	}
	catch(std::exception &kk)
	{
		std::cout << kk.what() << std::endl;
	}
	delete pingouin;
	delete Formol;
}


