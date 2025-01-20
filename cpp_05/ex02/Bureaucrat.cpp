#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat():_name("Default") , _grade(0)
{}

Bureaucrat::Bureaucrat(std::string name, int grade):_name(name)
{
	if(grade < 1)
		throw GradeTooHighException();
	else if(grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade)
{
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureacrat default destructer called" << std::endl;
}

Bureaucrat* Bureaucrat::operator=(const Bureaucrat &other)
{
	if(this != &other)
	{
		/*name cont olduğu için eşitleme yapılamıyor*/
		_grade = other._grade;
	}
	return this;
}

std::string Bureaucrat::getName() const {return _name;}
int Bureaucrat::getGrade() const {return _grade;}

void Bureaucrat::promotion(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if(grade > _grade)
		std::cout << "There is a demotion";
	else
		_grade = grade;
}

void Bureaucrat::demotion(int grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if(grade < _grade)
		std::cout << "There is a promotion";
	else
		_grade = grade;
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &brcrt)
{
	out << brcrt.getName() << ", bureaucrat grade "  << brcrt.getGrade() << std::endl;
	return out;
}


// ex01
void Bureaucrat::singForm(const Form& form)
{
	if(form.getSing())
		std::cout << _name << " singed " << form.getName() << std::endl;
	else
		std::cout << _name << " couldn’t sign " << form.getName() << " bcause " << "grade is to low" << std::endl;
}

// ex02
void Bureaucrat::executeForm(const Form &form)
{
	if(form.getSing())
		std::cout << _name << " executed " << form.getName() << std::endl;
	else
		std::cout << _name << " couldn’t execute " << form.getName() << " bcause " << "grade is to low" << std::endl;
}