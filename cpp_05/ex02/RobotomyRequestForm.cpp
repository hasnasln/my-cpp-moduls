#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target) {}


RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm* RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this == &other)
		return this;
	AForm::operator=(other);
	return this;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	std::cout << "*drilling noises* ";
	if (rand() % 2)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << _target << " robotomization failed" << std::endl;
}

AForm* RobotomyRequestForm::clone(std::string target) const {
	return new RobotomyRequestForm(target);
}
