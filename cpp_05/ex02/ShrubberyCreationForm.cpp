#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm():AForm("Default", 0, 0)
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):AForm(target, 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):AForm(other)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm default destructer called" << std::endl;
}

ShrubberyCreationForm* ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if(this != &other)
	{
		AForm::operator=(other);
	}
	return this;
}

void ShrubberyCreationForm::beSinged(const Bureaucrat &brctrt)
{
	if(brctrt.getGrade() <= getMinGradeToSing())
		AForm::beSinged(brctrt);
	else
		throw AForm::GradeTooLowException();
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if(executor.getGrade() <= getMinGradeToExecute())
	{
		std::ofstream file(getName() + "_shrubbery");
		file << "       _-_\n    /~~   ~~\\\n /~~         ~~\\\n{               }\n \\  _-     -_  /\n   ~  \\\\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\\n";
		file.close();
	}
	else
		throw AForm::GradeTooLowException();
}
