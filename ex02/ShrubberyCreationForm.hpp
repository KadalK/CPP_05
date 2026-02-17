#ifndef SHRUBBERYCREACTIONFORM_HPP
#define SHRUBBERYCREACTIONFORM_HPP

#include <iostream>
#include <exception>
#include <string>
#include <fstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
private:
	std::string		_target;
	std::string		_name;
	bool			_signed;
	int	const		_gradeToSign;
	int	const		_gradeToExe;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string );
	ShrubberyCreationForm(const ShrubberyCreationForm& );
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& );

	bool				getSigned() const;
	int					getGradeExe() const;
	int					getGradeSign() const;
	std::string	const	getName() const;

	void	setSigned(bool );

	void	beSigned(Bureaucrat& );
	void	execute(Bureaucrat const & ) const;

	virtual ~ShrubberyCreationForm();
};

#endif