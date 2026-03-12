#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <cstddef>


int main()
{
	Bureaucrat *pingouin = NULL;
	Form *Formol = NULL;

	pingouin = new Bureaucrat("Pin");
	pingouin->setGrade(77);
	Formol =  new Form(66);
	std::cout << *pingouin << std::endl;
	std::cout << *Formol << std::endl;
	pingouin->signForm(*Formol);

	delete pingouin;
	delete Formol;
}
