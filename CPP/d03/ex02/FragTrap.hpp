#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

public:

	FragTrap( void );
	FragTrap( std::string const & name );
	FragTrap( FragTrap const & src );
	~FragTrap( void );

	FragTrap &	operator=( FragTrap const & rhs );

	void		vaulthunter_dot_exe( std::string const & target );

private:

	void		(FragTrap::*_specialAttacks[5])( std::string const & target );

	void		initSpecialAttacks( void );
	void		trempette( std::string const & target );
	void		frenchBaguette( std::string const & target );
	void		expelliarmus( std::string const & target );
	void		turtleShell( std::string const & target );
	void		kamehameha( std::string const & target );

};

#endif