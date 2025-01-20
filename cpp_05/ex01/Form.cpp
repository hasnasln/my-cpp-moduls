#include "Form.hpp"
#include <iostream>

#include "Bureaucrat.hpp"

Form::Form():_name("default"), _sing(false), _minGradeToSing(0), _minGradeToExecute(0)
{}

Form::Form(std::string const name, int minGradeToSing, int minGradeToExecute): _name(name), _sing(false), _minGradeToSing(minGradeToSing),
_minGradeToExecute(minGradeToExecute)
{}

Form::Form(const Form& other):_name(other._name), _sing(other._sing), _minGradeToSing(other._minGradeToSing),
_minGradeToExecute(other._minGradeToExecute)
{}

Form::~Form()
{
	std::cout << "From default destracture called" << std::endl;
}

Form* Form::operator=(const Form& other)
{
	if(this != &other)
	{
		_sing = other._sing;
	}
	return this;
}

void Form::beSinged(const Bureaucrat& brctrt)
{
	if(brctrt.getGrade() <= _minGradeToSing)
		_sing = true;
	else
		throw GradeTooLowException();
}

bool Form::getSing() const {return _sing;}
std::string Form::getName()const {return _name;}

std::ostream& operator<<(std::ostream &out, const Form &frm)
{
	out << "Form name: " << frm.getName() << std::endl;
	out << "Form sing: " << frm.getSing() << std::endl;
	return out;
}