//
// Created by Khalifa Almheiri on 2/24/23.
//

#ifndef CPP_MODULE_05_SHRUBBERYCREATIONFORM_HPP
#define CPP_MODULE_05_SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#define TREE_FILE "trees.txt"
class ShrubberyCreationForm : public AForm {
	std::string				_target;
public:
	ShrubberyCreationForm (void);
	ShrubberyCreationForm (const ShrubberyCreationForm &);
	ShrubberyCreationForm (const std::string &);
	ShrubberyCreationForm (const char *);
	ShrubberyCreationForm	&operator= (const ShrubberyCreationForm &);
	~ShrubberyCreationForm (void);
	void					execute (const Bureaucrat &) const;
};


#endif //CPP_MODULE_05_SHRUBBERYCREATIONFORM_HPP
