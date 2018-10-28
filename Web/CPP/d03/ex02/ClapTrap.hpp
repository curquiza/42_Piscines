#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {

public:

	ClapTrap( void );
	ClapTrap(
		unsigned int hitPoints,
		unsigned int MaxHitPoints,
		unsigned int energyPoints,
		unsigned int MaxEnergyPoints,
		unsigned int level,
		std::string const & name,
		unsigned int meleeAttackDamage,
		unsigned int rangedAttackDamage,
		unsigned int armorDamageReducton );
	ClapTrap( ClapTrap const & src );
	~ClapTrap( void );

	std::string	getName ( void ) const;

	ClapTrap & operator=( ClapTrap const & rhs);

	void		rangedAttack( std::string const & target ) const;
	void		meleeAttack( std::string const & target ) const;
	void		takeDamage( unsigned int amount );
	void		beRepaired( unsigned int amount );

protected:

	unsigned int	_hitPoints;
	unsigned int	_MaxHitPoints;
	unsigned int	_energyPoints;
	unsigned int	_MaxEnergyPoints;
	unsigned int	_level;
	std::string		_name;
	unsigned int	_meleeAttackDamage;
	unsigned int	_rangedAttackDamage;
	unsigned int	_armorDamageReducton;

private:

};

#endif