//
// Created by Khalifa Almheiri on 2/24/23.
//

#ifndef CPP_MODULE_05_ROBOTOMYREQUESTFORM_HPP
#define CPP_MODULE_05_ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"

class RobotomyRequestForm: public AForm {
	std::string				_target;
	public:
		RobotomyRequestForm (void);
		RobotomyRequestForm (const RobotomyRequestForm &);
		RobotomyRequestForm (const std::string &);
		RobotomyRequestForm (const char *);
		RobotomyRequestForm	&operator= (const RobotomyRequestForm &);
		~RobotomyRequestForm (void);
		void				execute (const Bureaucrat &) const;
};


#endif //CPP_MODULE_05_ROBOTOMYREQUESTFORM_HPP
