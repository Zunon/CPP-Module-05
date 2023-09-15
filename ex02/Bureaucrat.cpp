//
// Created by kalmheir on 2/20/23.
//

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void):
	_name("Hermes"), _grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat &other):
	_name(other._name), _grade(other._grade) {}

Bureaucrat::Bureaucrat(const std::string &name,  unsigned char grade):
	_name(name), _grade(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const char *name,  unsigned char grade):
	_name(name), _grade(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
		_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(void) {}

const char *Bureaucrat::GradeTooHighException::what(void) const throw() {
	return ("Grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw() {
	return ("Grade is too low");
}

std::string Bureaucrat::getName(void) const {
	return (_name);
}

int Bureaucrat::getGrade(void) const {
	return (_grade);
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade "
		<< bureaucrat.getGrade();
	return (out);
}

void	Bureaucrat::incrementGrade(void) {
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade(void) {
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

bool	Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
		return (true);
	} catch (GradeTooLowException &e) {
		std::cout << _name << " couldn't sign " << form.getName()
				  << " because " << e.what() << std::endl;
		return (false);
	}
}

bool	Bureaucrat::executeForm(AForm &form) {
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
		return (true);
	} catch (GradeTooLowException &e) {
		std::cout << _name << " couldn't execute " << form.getName()
				  << " because " << e.what() << std::endl;
		return (false);
	} catch (AForm::FormNotSignedException &e) {
		std::cout << _name << " couldn't execute " << form.getName()
				  << " because " << e.what() << std::endl;
		return (false);
	} catch (AForm::GradeTooHighException &e) {
		std::cout << _name << " couldn't execute " << form.getName()
				  << " because " << e.what() << std::endl;
		return (false);
	}
}