#include "Intern.hpp"

Intern::Intern( void ) {
	
	initNames();
	initActions();
	std::cout << "Intern CONSTRUCTOR" << std::endl;
	return ;
}


Intern::~Intern( void ) {

	std::cout << "Intern DESTRCUTOR" << std::endl;
	return ;
}

 Form *	Intern::makeForm(std::string const & name, std::string const & target) {

	// if (name == "president pardon")
	// {
	// 	std::cout << "Intern creates " << name << " form." << std::endl;
	// 	return (new PresidentialPardonForm::PresidentialPardonForm(target));
	// }
	// else if (name == "robotomy request")
	// {
	// 	std::cout << "Intern creates " << name << " form." << std::endl;
	// 	return (new RobotomyRequestForm::RobotomyRequestForm(target));
	// }
	// else if (name == "shrubbery creation")
	// {
	// 	std::cout << "Intern creates " << name << " form." << std::endl;
	// 	return (new ShrubberyCreationForm::ShrubberyCreationForm(target));
	// }

	for (int i = 0; i < ACTIONS_NB; i++)
	{
		if (_validNames[i] == name)
		{
			std::cout << "Intern creates " << name << " form." << std::endl;
			return (this->*_actions[i])(target);
		}
	}
	std::cerr << "Unknown name of form." << std::endl;
	return (NULL);
}

void	Intern::initNames() {

	_validNames[0] = "president pardon";
	_validNames[1] = "robotomy request";
	_validNames[2] = "shrubbery creation";
	return ;
}

void	Intern::initActions() {
	
	_actions[0] = &Intern::makePresident;
	_actions[1] = &Intern::makeRobot;
	_actions[2] = &Intern::makeShrubbery;
	return ;
}

Form *	Intern::makePresident( std::string const & target ) {
	return (new PresidentialPardonForm::PresidentialPardonForm(target));
}

Form *	Intern::makeRobot( std::string const & target ) {
	return (new RobotomyRequestForm::RobotomyRequestForm(target));
}

Form *	Intern::makeShrubbery( std::string const & target ) {
	return (new ShrubberyCreationForm::ShrubberyCreationForm(target));
}

/* UNUSED */
Intern::Intern( Intern const & ) {}
Intern &	Intern::operator=( Intern const & ) { return *this ; }
