/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:55:34 by kalmheir          #+#    #+#             */
/*   Updated: 2023/09/15 14:23:30 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern;

typedef struct s_formType {
    std::string name;
    AForm *(Intern::*make)(std::string target);
} t_formType;

class Intern {
    private:
        static t_formType _formTypes[3];
        AForm *makeShrubberyCreationForm(std::string target);
        AForm *makeRobotomyRequestForm(std::string target);
        AForm *makePresidentialPardonForm(std::string target);
    public:
        Intern(void);
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        ~Intern(void);
        AForm *makeForm(std::string name, std::string target);
        AForm *makeForm(const char *name, std::string target);
        AForm *makeForm(std::string name, const char *target);
        AForm *makeForm(const char *name, const char *target);
};

#endif