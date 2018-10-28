#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

# define ACTIONS_NB 3

class Intern {

private:

	std::string	_validNames[ACTIONS_NB];
	Form *		(Intern::*_actions[ACTIONS_NB])( std::string const & target );

	void	initNames();
	void	initActions();

	Form *		makePresident( std::string const & target );
	Form *		makeRobot( std::string const & target );
	Form *		makeShrubbery( std::string const & target );

	/* unused */
	Intern( Intern const & );
	Intern & operator=( Intern const & );

public:

	Intern( void );
	~Intern( void );

	Form *	makeForm(std::string const & name, std::string const & target);

};

#endif