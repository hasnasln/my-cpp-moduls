#include "AForm.hpp"
#include <iostream>

#include "Bureaucrat.hpp"

AForm::AForm():_name("default"), _sing(false), _minGradeToSing(0), _minGradeToExecute(0)
{}

AForm::AForm(std::string const name, int minGradeToSing, int minGradeToExecute): _name(name), _sing(false), _minGradeToSing(minGradeToSing),
_minGradeToExecute(minGradeToExecute)
{}

AForm::AForm(const AForm& other):_name(other._name), _sing(other._sing), _minGradeToSing(other._minGradeToSing),
_minGradeToExecute(other._minGradeToExecute)
{}

AForm::~AForm()
{
	std::cout << "Form default destracture called" << std::endl;
}

AForm* AForm::operator=(const AForm& other)
{
	if(this != &other)
	{
		_sing = other._sing;
	}
	return this;
}

void AForm::beSinged(const Bureaucrat& brctrt)
{
	if(brctrt.getGrade() <= _minGradeToSing)
		_sing = true;
	else
		throw GradeTooLowException();
}

bool AForm::getSing() const {return _sing;}
std::string AForm::getName()const {return _name;}
int AForm::getMinGradeToSing() const {return _minGradeToSing;}
int AForm::getMinGradeToExecute() const {return _minGradeToExecute;}

std::ostream& operator<<(std::ostream &out, const AForm &frm)
{
	out << "AForm name: " << frm.getName() << std::endl;
	out << "AForm sing: " << frm.getSing() << std::endl;
	return out;
}