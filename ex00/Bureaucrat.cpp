//
// Created by kalmheir on 2/20/23.
//

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) {
	_name = "Hermes";
	_grade = 150;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) {
	_name = other._name;
	_grade = other._grade;
}

Bureaucrat::Bureaucrat(const std::string &name, unsigned char grade) {
	if (grade < 1)
		throw GradeTooHighException(grade);
	if (grade > 150)
		throw GradeTooLowException(grade);
	_name = name;
	_grade = grade;
}