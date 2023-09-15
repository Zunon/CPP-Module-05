//
// Created by Khalifa Almheiri on 2/24/23.
//

#ifndef CPP_MODULE_05_FORM_HPP
#define CPP_MODULE_05_FORM_HPP
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;
	public:
		Form (void);
		Form (const Form &);
		Form (const std::string &name, int gradeToSign, int gradeToExecute);
		Form (const char *name, int gradeToSign, int gradeToExecute);
		Form				&operator= (const Form &);
		~Form (void);
		std::string 		getName (void) const;
		bool				getIsSigned (void) const;
		int					getGradeToSign (void) const;
		int					getGradeToExecute (void) const;
		void				beSigned (const Bureaucrat &);

	class GradeTooHighException: public std::exception {
		public:
			const char	*what (void) const throw ();
	};

	class GradeTooLowException: public std::exception {
		public:
			const char	*what(void) const throw();
	};
};

std::ostream	&operator<< (std::ostream &, const Form &);
#endif //CPP_MODULE_05_FORM_HPP
