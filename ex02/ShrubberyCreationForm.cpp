//
// Created by Khalifa Almheiri on 2/24/23.
//

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
: AForm ("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
: AForm(src), _target(src._target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const char *target)
: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
		const ShrubberyCreationForm &rhs) {
	if (this != &rhs) {
		AForm::operator=(rhs);
		_target = rhs._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	// TODO
}