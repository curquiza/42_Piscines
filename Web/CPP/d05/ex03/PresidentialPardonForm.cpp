#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) :
	Form::Form("President", 25, 5),
	_target("home") {

	std::cout << "PresidentialPardonForm CONSTRUCTOR" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( std::string const target ) : 
	Form::Form("President", 25, 5), _target(target) {
	std::cout << "PresidentialPardonForm CONSTRUCTOR" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & ) {}

PresidentialPardonForm::~PresidentialPardonForm( void ) {
	std::cout << "PresidentialPardonForm DESTRUCTOR" << std::endl;
	return ;
}

void	PresidentialPardonForm::executeChildForm() const {

	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	return ;
}

std::string	PresidentialPardonForm::getTarget() { return _target; }

/* OVERLOAD */
PresidentialPardonForm &	PresidentialPardonForm::operator=( PresidentialPardonForm const & ) { return *this ; }