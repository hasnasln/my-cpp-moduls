#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>

#include "Bureaucrat.hpp"
// İleri bildirim kullanımı
class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(std::string name, int _minGradeToSing, int _minGradeToExecute);
		AForm(const AForm& other);
		~AForm();
		AForm* operator=(const AForm& other);
		virtual void beSinged(const Bureaucrat& brctrt) = 0;

		bool getSing() const;
		std::string getName() const;
		int getMinGradeToSing() const;
		int getMinGradeToExecute() const;
		
		/*----------------Exception----------------------*/
		class GradeTooHighException: public std::exception {
			public:
				const char *what() const throw() {
					return "Grade is to high";
				}
		};
		class GradeTooLowException: public std::exception {
			public:
				const char *what() const throw() {
					return "Grade is to low";
				}
		};
	private:
		std::string const _name;
		bool _sing;
		const int _minGradeToSing;
		const int _minGradeToExecute;
};

std::ostream& operator<<(std::ostream &out, const AForm &frm);

#endif // FORM_HPP
