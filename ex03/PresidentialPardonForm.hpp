//
// Created by Khalifa Almheiri on 2/24/23.
//

#ifndef CPP_MODULE_05_PRESIDENTIALPARDONFORM_HPP
#define CPP_MODULE_05_PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"

class PresidentialPardonForm: public AForm {
	std::string					_target;
	public:
		PresidentialPardonForm (void);
		PresidentialPardonForm (const PresidentialPardonForm &);
		PresidentialPardonForm (const std::string &);
		PresidentialPardonForm (const char *);
		PresidentialPardonForm	&operator= (const PresidentialPardonForm &);
		~PresidentialPardonForm (void);
		void					execute (const Bureaucrat &) const;
};


#endif //CPP_MODULE_05_PRESIDENTIALPARDONFORM_HPP
