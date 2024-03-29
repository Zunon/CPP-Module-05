//
// Created by Khalifa Almheiri on 2/24/23.
//

#ifndef CPP_MODULE_05_AFORM_HPP
#define CPP_MODULE_05_AFORM_HPP
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;
	public:
		AForm (void);
		AForm (const AForm &);
		AForm (const std::string &name, int gradeToSign, int gradeToExecute);
		AForm (const char *name, int gradeToSign, int gradeToExecute);
		AForm				&operator= (const AForm &);
		virtual ~AForm (void);
		std::string 		getName (void) const;
		bool				getIsSigned (void) const;
		int					getGradeToSign (void) const;
		int					getGradeToExecute (void) const;
		void				beSigned (const Bureaucrat &);
		virtual void		execute (const Bureaucrat &) const = 0;

	class GradeTooHighException: public std::exception {
		public:
			const char	*what (void) const throw ();
	};

	class GradeTooLowException: public std::exception {
		public:
			const char	*what(void) const throw();
	};

	class FormNotSignedException: public std::exception {
		public:
			const char	*what(void) const throw();
	};
};

std::ostream	&operator<< (std::ostream &, const AForm &);
#endif //CPP_MODULE_05_AFORM_HPP
