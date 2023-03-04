//
// Created by Khalifa Almheiri on 2/24/23.
//

#include "Form.hpp"

Form::Form(void):
	_name("Form Creation Form"), _isSigned(false), _gradeToSign(150),
	_gradeToExecute(150) {}

Form::Form(const Form &other):
	_name(other._name), _isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute) {}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute):
	_name(name), _isSigned(false), _gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const char *name, int gradeToSign, int gradeToExecute):
	_name(name), _isSigned(false), _gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form	&Form::operator=(const Form &other) {
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

Form::~Form(void) {}

std::string	Form::getName(void) const {
	return (_name);
}

bool	Form::getIsSigned(void) const {
	return (_isSigned);
}

int	Form::getGradeToSign(void) const {
	return (_gradeToSign);
}

int	Form::getGradeToExecute(void) const {
	return (_gradeToExecute);
}

void	Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	else
		_isSigned = true;
}

const char	*Form::GradeTooHighException::what(void) const throw() {
	return ("Grade is too high");
}

const char	*Form::GradeTooLowException::what(void) const throw() {
	return ("Grade is too low");
}

std::ostream	&operator<<(std::ostream &out, const Form &form) {
	out	<< "Form name: " << form.getName() << std::endl
		<< "Form is signed: " << form.getIsSigned() << std::endl
		<< "Grade to sign: " << form.getGradeToSign() << std::endl
		<< "Grade to execute: " << form.getGradeToExecute() << std::endl;
	return (out);
}