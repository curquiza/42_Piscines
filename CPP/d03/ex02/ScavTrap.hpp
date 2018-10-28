#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public:

	ScavTrap( void );
	ScavTrap( std::string const & name );
	ScavTrap( ScavTrap const & src );
	~ScavTrap( void );

	ScavTrap &	operator=( ScavTrap const & rhs );

	void		challengeNewcomer( std::string const & target );
	
private:

	void		(ScavTrap::*_challenges[5])( std::string const & target );

	void		initChallenges( void );
	void		yugiohDuel( std::string const & target );
	void		concomberCat( std::string const & target );
	void		PHPCleanCode( std::string const & target );
	void		marioKart( std::string const & target );
	void		rattataChallenge( std::string const & target );

};

#endif