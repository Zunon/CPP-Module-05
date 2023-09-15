//
// Created by kalmheir on 2/20/23.
//
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {
	// ShrubberyCreationForm
	Bureaucrat hermes("Hermes Conrad", 37);
	Bureaucrat bob("Bobby Bobson", 123);
	Bureaucrat zaphod("Zaphod Beeblebrox", 1);
	ShrubberyCreationForm form("home");
	std::cout << hermes << std::endl;
	std::cout << bob << std::endl;
	std::cout << form << std::endl;
	bob.signForm(form);
	bob.executeForm(form);
	// RobotomyRequestForm
	RobotomyRequestForm form2("Bender");
	std::cout << form2 << std::endl;
	hermes.signForm(form2);
	hermes.executeForm(form2);
	// PresidentialPardonForm
	PresidentialPardonForm form3("Bender");
	std::cout << form3 << std::endl;
	zaphod.signForm(form3);
	zaphod.executeForm(form3);
	return (EXIT_SUCCESS);
}
