#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();
		ShrubberyCreationForm* operator=(const ShrubberyCreationForm &other);
		void beSinged(const Bureaucrat &brctrt);
		void execute(Bureaucrat const & executor) const;
	private:
		std::string const _target;
};

#endif // SHRUBBERYCREATIONFORM_HPP