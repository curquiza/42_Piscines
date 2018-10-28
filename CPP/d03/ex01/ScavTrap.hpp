#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>

class ScavTrap {

public:

	ScavTrap( void );
	ScavTrap( std::string const & name );
	ScavTrap( ScavTrap const & src );
	~ScavTrap( void );

	ScavTrap &	operator=( ScavTrap const & rhs );

	std::string	getName ( void ) const;

	void		rangedAttack( std::string const & target ) const;
	void		meleeAttack( std::string const & target ) const;
	void		takeDamage( unsigned int amount );
	void		beRepaired( unsigned int amount );

	void		challengeNewcomer( std::string const & target );
	
private:

	unsigned int	_hitPoints;
	unsigned int	_MaxHitPoints;
	unsigned int	_energyPoints;
	unsigned int	_MaxEnergyPoints;
	unsigned int	_level;
	std::string		_name;
	unsigned int	_meleeAttackDamage;
	unsigned int	_rangedAttackDamage;
	unsigned int	_armorDamageReducton;
	void			(ScavTrap::*_challenges[5])( std::string const & target );

	void		initChallenges( void );
	void		yugiohDuel( std::string const & target );
	void		concomberCat( std::string const & target );
	void		PHPCleanCode( std::string const & target );
	void		marioKart( std::string const & target );
	void		rattataChallenge( std::string const & target );

};

#endif