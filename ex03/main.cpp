#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	AForm *form = NULL;
	try
	{
		Bureaucrat test;
		Intern Intern;
		form = Intern.makeForm("robotomy request", "");
		if (form)
		{
			test.gradeDown();
			test.signForm(form);
			test.executeForm(*form);
		}
	}
	catch (std::exception &e)
	{
	}
	std::cout << "\n===================================================="
			  << std::endl;
	delete form;
	return 0;
}


