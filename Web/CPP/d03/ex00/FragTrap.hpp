#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>

class FragTrap {

public:

	FragTrap( void );
	FragTrap( std::string const & name );
	FragTrap( FragTrap const & src );
	~FragTrap( void );

	FragTrap &	operator=( FragTrap const & rhs );

	std::string	getName ( void ) const;

	void		rangedAttack( std::string const & target ) const;
	void		meleeAttack( std::string const & target ) const;
	void		takeDamage( unsigned int amount );
	void		beRepaired( unsigned int amount );

	void		vaulthunter_dot_exe( std::string const & target );

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
	void			(FragTrap::*_specialAttacks[5])( std::string const & target );

	void		initSpecialAttacks( void );
	void		trempette( std::string const & target );
	void		frenchBaguette( std::string const & target );
	void		expelliarmus( std::string const & target );
	void		turtleShell( std::string const & target );
	void		kamehameha( std::string const & target );

};

#endif