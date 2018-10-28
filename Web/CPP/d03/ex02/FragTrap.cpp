#include "FragTrap.hpp"

FragTrap::FragTrap( void ) :
	ClapTrap::ClapTrap() {

	srand (time(NULL));
	this->initSpecialAttacks();
	std::cout << "FR4G-TP " << this->_name << " is born 🤖" << std::endl;
	return ;
}

FragTrap::FragTrap( std::string const & name ) :
	ClapTrap::ClapTrap(100, 100, 100, 100, 1, name, 30, 20, 5) {

	srand (time(NULL));
	this->initSpecialAttacks();
	std::cout << "FR4G-TP " << this->_name << " is born 🤖" << std::endl;
	return ;
}

FragTrap::FragTrap( FragTrap const & src ) :
	ClapTrap::ClapTrap( src ) {

	srand (time(NULL));
	*this = src;
	std::cout << "FR4G-TP " << this->_name << " is born 🤖" << std::endl;
	return ;
}

FragTrap::~FragTrap( void ) {

	std::cout << "FR4G-TP " << this->_name << " is dead ☠️" << std::endl;
	return ;
}

FragTrap &		FragTrap::operator=( FragTrap const & rhs ) {
	
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
		this->_specialAttacks[0] = rhs._specialAttacks[0];
		this->_specialAttacks[1] = rhs._specialAttacks[1];
		this->_specialAttacks[2] = rhs._specialAttacks[2];
		this->_specialAttacks[3] = rhs._specialAttacks[3];
		this->_specialAttacks[4] = rhs._specialAttacks[4];
	}
	return *this ;
}

// SPECIAL ATTACKS

void			FragTrap::initSpecialAttacks ( void ) {

	this->_specialAttacks[0] = &FragTrap::trempette;
	this->_specialAttacks[1] = &FragTrap::frenchBaguette;
	this->_specialAttacks[2] = &FragTrap::expelliarmus;
	this->_specialAttacks[3] = &FragTrap::turtleShell;
	this->_specialAttacks[4] = &FragTrap::kamehameha;

	return ;
}

void			FragTrap::trempette( std::string const & target ) {

	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " with its special attack Trempette !!!" <<std::endl;
	std::cout << "But nothing happened..." << std::endl;

	return ;
}

void			FragTrap::frenchBaguette( std::string const & target ) {

	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " with its special attack French Baguette !!!" <<std::endl;
	std::cout << target << " is really hungry now..." << std::endl;

	return ;
}

void			FragTrap::expelliarmus( std::string const & target ) {

	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " with its special attack Expelliarmus !!!" <<std::endl;
	std::cout << target << " does not care because " << target << " does not have any wand !" << std::endl;

	return ;
}

void			FragTrap::turtleShell( std::string const & target ) {

	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " with its special attack Turtle Shell !!!" <<std::endl;
	std::cout << target << " takes some damages !" << std::endl;

	return ;
}

void			FragTrap::kamehameha( std::string const & target ) {

	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " with its special attack KAMEHAMEHA !!!" <<std::endl;
	std::cout << target << " takes a lot of damages !" << std::endl;

	return ;
}

void			FragTrap::vaulthunter_dot_exe( std::string const & target ) {

	int		r = rand() % 5;

	std::cout << "FR4G-TP " << this->_name << " is trying to invoke its special attack..." << std::endl;

	if (this->_energyPoints < 25)
	{
		std::cout << "Impossible !!! FR4G-TP " << this->_name << " does not have enough energy points !" << std::endl;
		return ;
	}	
	(this->*_specialAttacks[r])(target);
	this->_energyPoints -= 25;

	return ;
}
