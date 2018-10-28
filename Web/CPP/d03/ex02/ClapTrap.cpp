#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) :
	_hitPoints(100),
	_MaxHitPoints(100),
	_energyPoints(50),
	_MaxEnergyPoints(50),
	_level(1),
	_name("Boby"),
	_meleeAttackDamage(20),
	_rangedAttackDamage(10),
	_armorDamageReducton(5){
	
	std::cout << "CL4P-TP " << this->_name << " is born 👤" << std::endl;
	return ;
}

ClapTrap::ClapTrap (
	unsigned int hitPoints,
	unsigned int MaxHitPoints,
	unsigned int energyPoints,
	unsigned int MaxEnergyPoints,
	unsigned int level,
	std::string const & name,
	unsigned int meleeAttackDamage,
	unsigned int rangedAttackDamage,
	unsigned int armorDamageReducton) : 
	_hitPoints(hitPoints),
	_MaxHitPoints(MaxHitPoints),
	_energyPoints(energyPoints),
	_MaxEnergyPoints(MaxEnergyPoints),
	_level(level),
	_name(name),
	_meleeAttackDamage(meleeAttackDamage),
	_rangedAttackDamage(rangedAttackDamage),
	_armorDamageReducton(armorDamageReducton) {

	std::cout << "CL4P-TP " << this->_name << " is born 👤" << std::endl;
	return ;
}

ClapTrap::ClapTrap( ClapTrap const & src ) {

	*this = src;
	std::cout << "CL4P-TP " << this->_name << " is born 👤" << std::endl;
	return ;
}

ClapTrap::~ClapTrap( void ) {

	std::cout << "CL4P-TP " << this->_name << " is dead ☠️" << std::endl;
	return ;
}

ClapTrap &		ClapTrap::operator=( ClapTrap const & rhs) {
	
	if ( this != &rhs )
	{
		this->_hitPoints = rhs._hitPoints;
		this->_MaxHitPoints = rhs._MaxHitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_MaxEnergyPoints = rhs._MaxEnergyPoints;
		this->_level = rhs._level;
		this->_name = rhs._name;
		this->_meleeAttackDamage = rhs._meleeAttackDamage;
		this->_rangedAttackDamage = rhs._rangedAttackDamage;
		this->_armorDamageReducton = rhs._armorDamageReducton;
	}
	return *this ;
}

std::string		ClapTrap::getName ( void ) const {

	return this->_name;
}

void			ClapTrap::takeDamage( unsigned int amount ) {

	std::cout << this->_name << " takes " << amount - this->_armorDamageReducton << " points of damages !" << std::endl;
	if (amount - this->_armorDamageReducton < this->_hitPoints)
		this->_hitPoints -= amount - this->_armorDamageReducton;
	else
		this->_hitPoints = 0;
	std::cout << this->_name << "'s hit points : " << this->_hitPoints << "/" << this->_MaxHitPoints << std::endl;

	return ;
}

void			ClapTrap::beRepaired( unsigned int amount ) {

	std::cout << this->_name << " gains " << amount << " hit points !" << std::endl;
	if (amount + this->_hitPoints <= this->_MaxHitPoints)
		this->_hitPoints += amount;
	else
		this->_hitPoints = this->_MaxHitPoints;
	std::cout << this->_name << "'s hit points : " << this->_hitPoints << "/" << this->_MaxHitPoints << std::endl;

	return ;
}

void			ClapTrap::rangedAttack( std::string const & target ) const {

	std::cout << this->_name << " attacks " << target << " at range, causing " << this->_rangedAttackDamage << " points of damage !" << std::endl;
	return ;
}

void			ClapTrap::meleeAttack( std::string const & target ) const {

	std::cout << this->_name << " attacks " << target << " at melee, causing " << this->_meleeAttackDamage << " points of damage !" << std::endl;
	return ;
}