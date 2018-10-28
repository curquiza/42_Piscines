#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form {

private:

	std::string		_target;

	RobotomyRequestForm & operator=( RobotomyRequestForm const & rhs );
	RobotomyRequestForm( RobotomyRequestForm const & src );

public:

	RobotomyRequestForm( void );
	RobotomyRequestForm( std::string const target );
	virtual ~RobotomyRequestForm( void );

	std::string		getTarget();
	virtual void	executeChildForm() const;

};

#endif