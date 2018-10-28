#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) :
	_hitPoints(100),
	_MaxHitPoints(100),
	_energyPoints(50),
	_MaxEnergyPoints(50),
	_level(1),
	_name("Boby"),
	_meleeAttackDamage(20),
	_rangedAttackDamage(15),
	_armorDamageReducton(3) {

	srand (time(NULL));
	this->initChallenges();
	std::cout << "SC4V-TP " << this->_name << " is born 👾" << std::endl;
	return ;
}

ScavTrap::ScavTrap( std::string const & name ) :
	_hitPoints(100),
	_MaxHitPoints(100),
	_energyPoints(50),
	_MaxEnergyPoints(50),
	_level(1),
	_name(name),
	_meleeAttackDamage(20),
	_rangedAttackDamage(15),
	_armorDamageReducton(3) {

	srand (time(NULL));
	this->initChallenges();
	std::cout << "SC4V-TP " << this->_name << " is born 👾" << std::endl;
	return ;
}

ScavTrap::ScavTrap( ScavTrap const & src ) {

	srand (time(NULL));
	*this = src;
	std::cout << "SC4V-TP " << this->_name << " is born 👾" << std::endl;
	return ;
}

ScavTrap::~ScavTrap( void ) {

	std::cout << "SC4V-TP " << this->_name << " is dead ☠️" << std::endl;
	return ;
}

std::string		ScavTrap::getName ( void ) const {

	return this->_name;
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

void			ScavTrap::initChallenges ( void ) {

	this->_challenges[0] = &ScavTrap::yugiohDuel;
	this->_challenges[1] = &ScavTrap::concomberCat;
	this->_challenges[2] = &ScavTrap::PHPCleanCode;
	this->_challenges[3] = &ScavTrap::marioKart;
	this->_challenges[4] = &ScavTrap::rattataChallenge;

	return ;
}

void			ScavTrap::rangedAttack( std::string const & target ) const {

	std::cout << "SC4V-TP " << this->_name << " attacks " << target << " at range, causing " << this->_rangedAttackDamage << " points of damage !" << std::endl;
	return ;
}

void			ScavTrap::meleeAttack( std::string const & target ) const {

	std::cout << "SC4V-TP " << this->_name << " attacks " << target << " at melee, causing " << this->_meleeAttackDamage << " points of damage !" << std::endl;
	return ;
}

void			ScavTrap::takeDamage( unsigned int amount ) {

	std::cout << "SC4V-TP " << this->_name << " takes " << amount - this->_armorDamageReducton << " points of damages !" << std::endl;
	if (amount - this->_armorDamageReducton < this->_hitPoints)
		this->_hitPoints -= amount - this->_armorDamageReducton;
	else
		this->_hitPoints = 0;
	std::cout << "SC4V-TP " << this->_name << " hit points : " << this->_hitPoints << "/" << this->_MaxHitPoints << std::endl;

	return ;
}

void			ScavTrap::beRepaired( unsigned int amount ) {

	std::cout << "SC4V-TP " << this->_name << " gains " << amount << " hit points !" << std::endl;
	if (amount + this->_hitPoints <= this->_MaxHitPoints)
		this->_hitPoints += amount;
	else
		this->_hitPoints = this->_MaxHitPoints;
	std::cout << "SC4V-TP " << this->_name << " hit points : " << this->_hitPoints << "/" << this->_MaxHitPoints << std::endl;

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