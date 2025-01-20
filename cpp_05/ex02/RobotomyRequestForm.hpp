#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"


class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		~RobotomyRequestForm();
		RobotomyRequestForm* operator=(const RobotomyRequestForm &other);
		void beSinged(const Bureaucrat &brctrt);
		void execute(const Bureaucrat &executor) const;
	private:
		std::string const _target;
};




#endif // ROBOTOMYREQUESTFORM_HPP