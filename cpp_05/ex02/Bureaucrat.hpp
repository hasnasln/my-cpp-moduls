#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

// İleri bildirim kullanımı
class Form;

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
        class GradeTooHighException: public std::exception {
            public:
                const char* what() const throw() {
                    return "Grade is to high";
                }
        };
        class GradeTooLowException: public std::exception {
            public:
                const char* what() const throw() {
                    return "Grade is to low";
                }
        };

        // ex01
        void singForm(const Form& form);
        // ex02
        void executeForm(const Form &form);
    private:
        std::string const _name;
        int _grade;
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &brcrt);

#endif // BUREAUCRAT_HPP
