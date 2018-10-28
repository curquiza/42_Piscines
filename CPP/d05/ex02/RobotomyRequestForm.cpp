#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) :
	Form::Form("Robot", 72, 45),
	_target("home") {

	srand (time(NULL));
	std::cout << "RobotomyRequestForm CONSTRUCTOR" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( std::string const target ) :
	Form::Form("Robot", 72, 45), _target(target) {

	srand (time(NULL));
	std::cout << "RobotomyRequestForm CONSTRUCTOR" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & ) {}

RobotomyRequestForm::~RobotomyRequestForm( void ) {

	std::cout << "RobotomyRequestForm DESTRUCTOR" << std::endl;
	return ;
}

void	RobotomyRequestForm::executeChildForm() const {

	int			r = rand() % 2;

	if (r == 0)
	{
		std::cout << "** VVVVVVVVVVVVVVVVVVO !!! **" << std::endl;
		std::cout << _target << " has been robotomized successfully." << std::endl;
	}
	else
		std::cout << "FAIL !" << std::endl;
	return ;
}

std::string	RobotomyRequestForm::getTarget() { return _target; }

/* OVERLOAD */
RobotomyRequestForm &	RobotomyRequestForm::operator=( RobotomyRequestForm const & ) { return *this ; }