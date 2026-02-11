#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern{
public:
	Intern();
	Intern(Intern& );
	Intern&  operator=(Intern& );

	class NullException : public std::exception {
		virtual const char* what() const throw();
	};

	AForm*	makeForm(std::string	form, std::string target);
	~Intern();
};

#endif