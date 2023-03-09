//
// Created by kalmheir on 2/20/23.
//
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
	ShrubberyCreationForm form("home");
	Bureaucrat bureaucrat("bureaucrat", 1);
	std::cout << form << std::endl;
	std::cout << bureaucrat << std::endl;
	bureaucrat.signForm(form);
	std::cout << form << std::endl;
	bureaucrat.executeForm(form);
	std::cout << form << std::endl;
	return (EXIT_SUCCESS);
}
