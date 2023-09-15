//
// Created by kalmheir on 2/20/23.
//
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void) {
	Intern intern;
	Bureaucrat hermes("Hermes Conrad", 37);
	Bureaucrat bob("Bobby Bobson", 123);
	Bureaucrat zaphod("Zaphod Beeblebrox", 1);
	AForm *form;
	form = intern.makeForm("shrubbery creation", "home");
	std::cout << *form << std::endl;
	hermes.signForm(*form);
	hermes.executeForm(*form);
	delete form;
	form = intern.makeForm("robotomy request", "Bender");
	std::cout << *form << std::endl;
	hermes.signForm(*form);
	hermes.executeForm(*form);
	delete form;
	form = intern.makeForm("presidential pardon", "Bender");
	std::cout << *form << std::endl;
	zaphod.signForm(*form);
	zaphod.executeForm(*form);
	delete form;	
	return (EXIT_SUCCESS);
}
