//
// Created by Khalifa Almheiri on 2/24/23.
//

#include "PresidentialPardonForm.hpp"
PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("PresidentialPardonForm", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm
&other) : AForm(other), _target(src._target) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const char *target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const
		PresidentialPardonForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (!getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox."
		<< std::endl;
}