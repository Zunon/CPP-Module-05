//
// Created by kalmheir on 2/20/23.
//
#include "Bureaucrat.hpp"
#include <cstdlib>

int main(void) {
	try {
		Bureaucrat b1("B1", 1);
		std::cout << b1 << std::endl;
		Bureaucrat b2("B2", 150);
		std::cout << b2 << std::endl;
		Bureaucrat b3("B3", 0);
		std::cout << b3 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
