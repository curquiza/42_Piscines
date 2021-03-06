#include "Fixed.hpp"

Fixed::Fixed( void ) : _fpValue(0) {

	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed( int const n ) {

	std::cout << "Int constructor called" << std::endl;
	this->_fpValue = n << Fixed::_fractionnal;
	return ;
}

Fixed::Fixed( float const n ) {

	std::cout << "Float constructor called" << std::endl;
	this->_fpValue = roundf(n * ( 1 << Fixed::_fractionnal ));
	return ;
}

Fixed::Fixed( Fixed const & src ) {

	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::~Fixed( void ) {

	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed &		Fixed::operator=( Fixed const & rhs) {

	std::cout << "Assignation operator called" << std::endl;
	if ( this != &rhs )
		this->_fpValue = rhs.getRawBits();
	return *this ;
}

int			Fixed::getRawBits( void ) const {

	return this->_fpValue;
}

void 		Fixed::setRawBits( int const raw ) {

	this->_fpValue = raw;
	return ;
}

float		Fixed::toFloat( void ) const {

	return  (static_cast<float>(this->_fpValue) / ( 1 << Fixed::_fractionnal ));
}

int			Fixed::toInt( void ) const {

	return (this->_fpValue) >> Fixed::_fractionnal;
}

std::ostream &	operator<<( std::ostream & o, Fixed const & rhs ) {

	o << rhs.toFloat();
	return o;
}

const int	Fixed::_fractionnal = 8;