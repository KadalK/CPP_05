#include "Bureaucrat.hpp"


int main()
{
	Bureaucrat *pin = NULL;

	try
	{
		pin = new Bureaucrat("Truc");
		pin->setGrade(2);
		pin->gradeUp();
		std::cout << *pin << std::endl;
		std::cout << pin->getGrade() << std::endl;
	}
	catch(std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
		delete pin;
}
