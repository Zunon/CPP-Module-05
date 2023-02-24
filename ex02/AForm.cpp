//
// Created by Khalifa Almheiri on 2/24/23.
//

#include "AForm.hpp"

AForm::AForm(void):
	_name("Form Creation Form"), _isSigned(false), _gradeToSign(150),
	_gradeToExecute(150) {}

AForm::AForm(const AForm &other):
	_name(other._name), _isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute) {}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute):
	_name(name), _isSigned(false), _gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const char *name, int gradeToSign, int gradeToExecute):
	_name(name), _isSigned(false), _gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm	&AForm::operator=(const AForm &other) {
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

AForm::~AForm(void) {}

std::string	AForm::getName(void) const {
	return (_name);
}

bool	AForm::getIsSigned(void) const {
	return (_isSigned);
}

int	AForm::getGradeToSign(void) const {
	return (_gradeToSign);
}

int	AForm::getGradeToExecute(void) const {
	return (_gradeToExecute);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		std::cout	<< bureaucrat.getName() << " cannot sign " << _name
					<< " because his grade is too low" << std::endl;
	else {
		std::cout << bureaucrat.getName() << " signs " << _name << std::endl;
		_isSigned = true;
	}
}

const char	*AForm::GradeTooHighException::what(void) const throw() {
	return ("Grade is too high");
}

const char	*AForm::GradeTooLowException::what(void) const throw() {
	return ("Grade is too low");
}

std::ostream	&operator<<(std::ostream &out, const AForm &form) {
	out	<< "Form name: " << form.getName() << std::endl
		<< "Form is signed: " << form.getIsSigned() << std::endl
		<< "Grade to sign: " << form.getGradeToSign() << std::endl
		<< "Grade to execute: " << form.getGradeToExecute() << std::endl;
	return (out);
}