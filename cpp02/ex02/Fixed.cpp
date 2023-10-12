/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 20:22:42 by mschaub           #+#    #+#             */
/*   Updated: 2023/07/29 08:24:44 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	this->_value = value << this->_bits;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << this->_bits));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
	std::cout << "Copy assignation operator called" << std::endl;
	this->_value = fixed.getRawBits();
	return *this;
}

bool	Fixed::operator>( const Fixed &fixed) const {
	return this->getRawBits() > fixed.getRawBits();
}

bool	Fixed::operator<( const Fixed &fixed ) const {
	return this->getRawBits() < fixed.getRawBits();
}

bool	Fixed::operator>=( const Fixed &fixed ) const {
	return this->getRawBits() >= fixed.getRawBits();
}

bool	Fixed::operator<=( const Fixed &fixed ) const {
	return this->getRawBits() <= fixed.getRawBits();
}

bool	Fixed::operator==( const Fixed &fixed ) const {
	return this->getRawBits() == fixed.getRawBits();
}

bool	Fixed::operator!=( const Fixed &fixed ) const {
	return this->getRawBits() != fixed.getRawBits();
}

Fixed	Fixed::operator+( const Fixed &fixed ) const {
	return Fixed( this->toFloat() + fixed.toFloat() );
}

Fixed	Fixed::operator-( const Fixed &fixed ) const {
	return Fixed( this->toFloat() - fixed.toFloat() );
}

Fixed	Fixed::operator*( const Fixed &fixed ) const {
	return Fixed( this->toFloat() * fixed.toFloat() );
}

Fixed	Fixed::operator/( const Fixed &fixed ) const {
	return Fixed( this->toFloat() / fixed.toFloat() );
}

Fixed	&Fixed::operator++( void ) { //prefix
	++this->_value;
	return *this;
}

Fixed	&Fixed::operator--( void ) { //prefix
	--this->_value;
	return *this;
}

Fixed	Fixed::operator++( int ) { //postfix
	Fixed tmp( *this );
	tmp._value = this->_value++;
	return tmp;
}

Fixed	Fixed::operator--( int ) { //postfix
	Fixed tmp( *this );
	tmp._value = this->_value--;
	return tmp;
}

Fixed	&Fixed::min( Fixed &a, Fixed &b ) {
	if (a.getRawBits() < b.getRawBits())
		return a;
	else
		return b;
}

Fixed	&Fixed::max( Fixed &a, Fixed &b ) {
	if (a.getRawBits() > b.getRawBits())
		return a;
	else
		return b;
}

const Fixed	&Fixed::min( const Fixed &a, const Fixed &b ) {
	if (a.getRawBits() < b.getRawBits())
		return a;
	else
		return b;
}

const Fixed	&Fixed::max( const Fixed &a, const Fixed &b ) {
	if (a.getRawBits() > b.getRawBits())
		return a;
	else
		return b;
}

int		Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

float	Fixed::toFloat( void ) const {
	return (float)this->_value / (float)(1 << this->_bits);
}

int		Fixed::toInt( void ) const {
	return this->_value >> this->_bits;
}

std::ostream & operator<<( std::ostream &o, Fixed const &i ) {
	o << i.toFloat();
	return o;
}
