#include "Bureaucrat.hpp"


int main()
{
	Bureaucrat *pin = NULL;

	try
	{
		pin = new Bureaucrat("Truc", 15);
		std::cout << *pin << std::endl;
		pin->gradeUp();
		try {
			for (int i = 0 ; i < 15 ; i++)
				pin->gradeUp();
		}
		catch(std::exception &ex) {
			std::cout << ex.what() << std::endl;
		}
		std::cout << *pin << std::endl;
		std::cout << "Setting Grade too 145" << std::endl;
		pin->setGrade(145);
		std::cout << *pin << std::endl;
		try {
			for (int i = 0 ; i < 10 ; i++)
				pin->gradeDown();
		}
		catch(std::exception &ex) {
			std::cout << ex.what() << std::endl;
		}
		std::cout << *pin << std::endl;
		std::cout << pin->getGrade() << std::endl;
	}
	catch(std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
		delete pin;
}
