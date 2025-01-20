#include <iostream>
#include <stdexcept>
#include <string>
class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();
		Bureaucrat* operator=(const Bureaucrat &other);
		std::string getName() const;
		int getGrade() const;
		void promotion(int grade);
		void demotion(int grade);
		class GradeTooHighException: public std::exception{
			public:
				const char* what() const throw() {
					return "Grade is to high";
				}
		};
		class GradeTooLowException: public std::exception{
			public:
				const char* what() const throw() {
					return "Grade is to low";
				}
		};
	private:
		std::string const _name;
		int _grade;
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &brcrt);

/*
Bir işlevin sonunda throw() belirtilmişse, bu işlevin herhangi bir istisna fırlatmayacağı anlamına gelir.
Bu, özellikle hata ayıklama ve güvenilir kod yazımı için faydalı olabilir.
*/