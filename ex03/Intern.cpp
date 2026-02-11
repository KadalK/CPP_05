#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(){}

Intern::Intern(Intern& copy){
	*this = copy;
}

Intern&  Intern::operator=(Intern& rhs){
	if (this != &rhs)
		return *this;
	return *this;
}

const char* Intern::NullException::what() const throw() {
	return (" does not exist");
}

AForm*	Intern::makeForm(std::string	form, std::string target)
{
	int i = 0;

	std::string tab[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (i = 0; i < 3; i++)
	{
		if (tab[i] == form)
			break;
	}

	switch (i) {
		case 0:
			std::cout << "Intern creates " << form << std::endl;
			return new ShrubberyCreationForm(target);
		case 1:
			std::cout << "Intern creates " << form << std::endl;
			return new RobotomyRequestForm(target);
		case 2:
			std::cout << "Intern creates " << form << std::endl;
			return new PresidentialPardonForm(target);
		default:
		{
			std::cout << "error:\n" << form;
			throw NullException();
		}
	}
}

Intern::~Intern(){}