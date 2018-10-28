#include "Fixed.hpp"

Fixed::Fixed( void ) : _fpValue(0) {

	return ;
}

Fixed::Fixed( int const n ) {

	this->_fpValue = n << Fixed::_fractionnal;
	return ;
}

Fixed::Fixed( float const n ) {

	this->_fpValue = roundf(n * ( 1 << Fixed::_fractionnal ));
	return ;
}

Fixed::Fixed( Fixed const & src ) {

	*this = src;
	return ;
}

Fixed::~Fixed( void ) {

	return ;
}

Fixed &		Fixed::operator=( Fixed const & rhs) {

	if ( this != &rhs )
		this->_fpValue = rhs.getRawBits();
	return *this ;
}

bool		Fixed::operator>( Fixed const & rhs) const {

	return (this->_fpValue > rhs.getRawBits());
}

bool		Fixed::operator<( Fixed const & rhs) const {

	return (this->_fpValue < rhs.getRawBits());
}

bool		Fixed::operator>=( Fixed const & rhs) const {

	return (this->_fpValue >= rhs.getRawBits());
}

bool		Fixed::operator<=( Fixed const & rhs) const {

	return (this->_fpValue <= rhs.getRawBits());
}

bool		Fixed::operator==( Fixed const & rhs) const {

	return (this->_fpValue == rhs.getRawBits());
}

bool		Fixed::operator!=( Fixed const & rhs) const {

	return (this->_fpValue != rhs.getRawBits());
}

Fixed const	Fixed::operator+( Fixed const & rhs ) const {

	return (Fixed (this->toFloat() + rhs.toFloat()));
}

Fixed const	Fixed::operator-( Fixed const & rhs ) const {

	return (Fixed (this->toFloat() - rhs.toFloat()));
}

Fixed const	Fixed::operator*( Fixed const & rhs ) const {

	return (Fixed (this->toFloat() * rhs.toFloat()));
}

Fixed const	Fixed::operator/( Fixed const & rhs ) const {

	return (Fixed (this->toFloat() / rhs.toFloat()));
}

int			Fixed::getRawBits( void ) const {

	return this->_fpValue;
}

void 		Fixed::setRawBits( int const raw ) {

	this->_fpValue = raw;
	return ;
}

float		Fixed::toFloat( void ) const {

	return  (static_cast<float>((this->_fpValue) / ( 1 << Fixed::_fractionnal )));
}

int			Fixed::toInt( void ) const {

	return (this->_fpValue) >> Fixed::_fractionnal;
}

std::ostream &	operator<<( std::ostream & o, Fixed const & rhs ) {

	o << rhs.toFloat();
	return o;
}

const int	Fixed::_fractionnal = 8;