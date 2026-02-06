#include "Bureaucrat.hpp"


int main()
{
	Bureaucrat *lol = new Bureaucrat;


	lol->setGrade(150);
	std::cout << lol << std::endl;
	try{
		lol->gradeUp();
	}
	catch(std::exception &kk)
	{
		std::cout << kk.what() << std::endl;
		delete lol;
	}
}


