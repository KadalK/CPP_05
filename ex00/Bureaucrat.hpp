#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <exception>
#include <string>

class Bureaucrat {
private:
	std::string	const	_name;
	int					_grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string& );
	Bureaucrat(const Bureaucrat& );

	int	getGrade() const;
	void	setGrade(int );

	std::string	const	getName() const;
	void	setName(std::string);

	void	gradeUp();
	void	gradeDown();

	class GradeTooHighException() : public std::exception {
		virtual const char* what() const noexcept;
	};

	class GradeTooLowException() : public std::exception {
		virtual const char* what() const noexcept;
	};

	virtual ~Bureaucrat();
};

#endif