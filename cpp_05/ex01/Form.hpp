#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>

// İleri bildirim kullanımı
class Bureaucrat;

class Form
{
    public:
        Form();
        Form(std::string name, int _minGradeToSing, int _minGradeToExecute);
        Form(const Form& other);
        ~Form();
        Form* operator=(const Form& other);
        void beSinged(const Bureaucrat& brctrt);
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
        bool getSing() const;
        std::string getName() const;

    private:
        std::string const _name;
        bool _sing;
        const int _minGradeToSing;
        const int _minGradeToExecute;
};

std::ostream& operator<<(std::ostream &out, const Form &frm);

#endif // FORM_HPP
