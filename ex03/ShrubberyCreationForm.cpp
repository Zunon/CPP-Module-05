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
	if (!getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::ofstream file;
	std::ifstream tree;
	std::string filename = _target + "_shrubbery";
	tree.open(TREE_FILE);
	file.open(filename.c_str());
	if (tree.is_open() && file.is_open()) {
		std::string line;
		while (getline(tree, line))
			file << line << std::endl;
	}
	else
		throw "Error opening file";
	file.close();
	tree.close();
}