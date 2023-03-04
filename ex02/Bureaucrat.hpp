//
// Created by kalmheir on 2/20/23.
//

#ifndef CPP_MODULE_05_BUREAUCRAT_HPP
# define CPP_MODULE_05_BUREAUCRAT_HPP
# include <string>
# include <iostream>
# include "AForm.hpp"

/**
 * @brief Bureaucrat class
 * @details Bureaucrat class
 * @param _name name of bureaucrat
 * @param _grade grade of bureaucrat, must be between 1 and 150
 */
class Bureaucrat {
    const std::string			_name;
    int							_grade;
	public:
		Bureaucrat (void);
		Bureaucrat (const Bureaucrat &);
		Bureaucrat (const std::string &name, unsigned char grade);
		Bureaucrat (const char *name, unsigned char grade);
		Bureaucrat				&operator= (const Bureaucrat &);
		~Bureaucrat (void);
		std::string 			getName (void) const;
		int						getGrade (void) const;
		void					incrementGrade (void);
		void					decrementGrade (void);
		bool					signForm (AForm &);

	class GradeTooHighException: public std::exception {
		public:
			const char	*what (void) const throw ();
	};

	class GradeTooLowException: public std::exception {
		public:
			const char	*what(void) const throw();
	};
};

std::ostream	&operator<< (std::ostream &, const Bureaucrat &);

#endif //CPP_MODULE_05_BUREAUCRAT_HPP
