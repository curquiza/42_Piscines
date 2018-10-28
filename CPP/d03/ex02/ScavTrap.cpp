#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) :
	ClapTrap::ClapTrap() {

	srand (time(NULL));
	this->initChallenges();
	std::cout << "SC4V-TP " << this->_name << " is born 👾" << std::endl;
	return ;
}

ScavTrap::ScavTrap( std::string const & name ) :
	ClapTrap::ClapTrap(100, 100, 50, 50, 1, name, 20, 15, 3) {

	srand (time(NULL));
	this->initChallenges();
	std::cout << "SC4V-TP " << this->_name << " is born 👾" << std::endl;
	return ;
}

ScavTrap::ScavTrap( ScavTrap const & src ) :
	ClapTrap::ClapTrap( src ) {

	srand (time(NULL));
	*this = src;
	std::cout << "SC4V-TP " << this->_name << " is born 👾" << std::endl;
	return ;
}

ScavTrap::~ScavTrap( void ) {

	std::cout << "SC4V-TP " << this->_name << " is dead ☠️" << std::endl;
	return ;
}

ScavTrap &		ScavTrap::operator=( ScavTrap const & rhs ) {
	
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
		this->_challenges[0] = rhs._challenges[0];
		this->_challenges[1] = rhs._challenges[1];
		this->_challenges[2] = rhs._challenges[2];
		this->_challenges[3] = rhs._challenges[3];
		this->_challenges[4] = rhs._challenges[4];
	}
	return *this ;
}

// CHALLENGES

void			ScavTrap::initChallenges ( void ) {

	this->_challenges[0] = &ScavTrap::yugiohDuel;
	this->_challenges[1] = &ScavTrap::concomberCat;
	this->_challenges[2] = &ScavTrap::PHPCleanCode;
	this->_challenges[3] = &ScavTrap::marioKart;
	this->_challenges[4] = &ScavTrap::rattataChallenge;

	return ;
}

void			ScavTrap::yugiohDuel( std::string const & target ) {

	std::cout << "FR4G-TP " << this->_name << " challenges " << target << " to a Yu-Gi-Oh duel !!!" <<std::endl;
	std::cout << "It's time to dddddddddddddddddduel !!!!" << std::endl;

	return ;
}

void			ScavTrap::concomberCat( std::string const & target ) {

	std::cout << "FR4G-TP " << this->_name << " challenges " << target << " to scare a cat with a concomber !!!" <<std::endl;
	std::cout << "Miiiew !!! 😿" << std::endl;

	return ;
}

void			ScavTrap::PHPCleanCode( std::string const & target ) {

	std::cout << "FR4G-TP " << this->_name << " challenges " << target << " to write a clean code in PHP !!!" <<std::endl;
	std::cout << target << " gives up." << std::endl;

	return ;
}

void			ScavTrap::marioKart( std::string const & target ) {

	std::cout << "FR4G-TP " << this->_name << " challenges " << target << " to Mario Kart with Peach Princess !!!" <<std::endl;
	std::cout << "Mariiiioo 😍" << std::endl;

	return ;
}

void			ScavTrap::rattataChallenge( std::string const & target ) {

	std::cout << "FR4G-TP " << this->_name << " challenges " << target << " to finish Pokemon Silver with one Rattata !!!" <<std::endl;
	std::cout << target << " would rather play to Pokemon Gold 🤓" << std::endl;

	return ;
}

void			ScavTrap::challengeNewcomer( std::string const & target ) {

	int		r = rand() % 5;

	std::cout << "FR4G-TP " << this->_name << " is thinking about a new challenge... 🤔" << std::endl;

	(this->*_challenges[r])(target);

	return ;
}