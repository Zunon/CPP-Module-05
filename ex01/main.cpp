//
// Created by kalmheir on 2/20/23.
//
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	try {
		Bureaucrat b1("B1", 1);
		std::cout << b1 << std::endl;
		Bureaucrat b2("B2", 150);
		std::cout << b2 << std::endl;
		// Bureaucrat b3("B3", 0);
		// std::cout << b3 << std::endl;
		Form f1("F1", 1, 1);
		std::cout << f1 << std::endl;
		f1.beSigned(b2);
		f1.beSigned(b1);
		Form f2("F2", 150, 150);
		std::cout << f2 << std::endl;
		Form f3("F3", 0, 0);
		std::cout << f3 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (EXIT_SUCCESS);
}