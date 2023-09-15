/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:55:32 by kalmheir          #+#    #+#             */
/*   Updated: 2023/09/15 14:33:32 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

t_formType Intern::_formTypes[3] = {
    {"shrubbery creation", &Intern::makeShrubberyCreationForm},
    {"robotomy request", &Intern::makeRobotomyRequestForm},
    {"presidential pardon", &Intern::makePresidentialPardonForm}
};

Intern::Intern(void) {}

Intern::Intern(const Intern &other) {
    *this = other;
}

Intern &Intern::operator=(const Intern &other) {
    if (this != &other) {
        *this = other;
    }
    return (*this);
}

Intern::~Intern(void) {}

AForm *Intern::makeShrubberyCreationForm(std::string target) {
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomyRequestForm(std::string target) {
    return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresidentialPardonForm(std::string target) {
    return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string name, std::string target) {
    for (int i = 0; i < 3; i++)
        if (name == _formTypes[i].name)
            return ((this->*_formTypes[i].make)(target));
    std::cout << "Form not found" << std::endl;
    return (NULL);
}

AForm *Intern::makeForm(const char *name, std::string target) {
    return (makeForm(std::string(name), target));
}

AForm *Intern::makeForm(std::string name, const char *target) {
    return (makeForm(name, std::string(target)));
}

AForm *Intern::makeForm(const char *name, const char *target) {
    return (makeForm(std::string(name), std::string(target)));
}

