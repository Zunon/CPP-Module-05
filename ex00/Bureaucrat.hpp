//
// Created by kalmheir on 2/20/23.
//

#ifndef CPP_MODULE_05_BUREAUCRAT_HPP
# define CPP_MODULE_05_BUREAUCRAT_HPP
# include <string>
# include <iostream>

/**
 * @brief Bureaucrat class
 * @details Bureaucrat class
 * @param _name name of bureaucrat
 * @param _grade grade of bureaucrat, must be between 1 and 150
 */
class Bureaucrat {
    const std::string	_name;
    int		_grade;
	public:
		Bureaucrat (void);
		Bureaucrat (const Bureaucrat &);
		Bureaucrat (const std::string &name, unsigned char grade);
		Bureaucrat (const char *name, unsigned char grade);
		Bureaucrat      &operator= (const Bureaucrat &);
		~Bureaucrat (void);
};

class GradeTooHighException: public std::exception {
	const char *    _message;
	unsigned char	_grade;
	public:
		GradeTooHighException (unsigned char);
		GradeTooHighException (const char *message);
		virtual const char  *what (void) const throw (void);
};

class GradeTooLowException: public std::exception {
	const char *_message;
	unsigned char _grade;
public:
	GradeTooLowException(unsigned char);
	GradeTooLowException(const char *message);
	virtual const char *what(void) const throw(void);
}

#endif //CPP_MODULE_05_BUREAUCRAT_HPP
