#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form {

private:

	std::string		_target;

	PresidentialPardonForm & operator=( PresidentialPardonForm const & rhs );
	PresidentialPardonForm( PresidentialPardonForm const & src );

public:

	PresidentialPardonForm( void );
	PresidentialPardonForm( std::string const target );
	virtual ~PresidentialPardonForm( void );

	std::string		getTarget();
	virtual void	executeChildForm() const;

};

#endif