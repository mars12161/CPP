/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:07:40 by mschaub           #+#    #+#             */
/*   Updated: 2023/06/27 17:23:06 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) {
	std::cout << "Animal default constructor called" << std::endl;
	this->_type = "Animal";
}

Animal::Animal( std::string type ) {
	std::cout << "Animal type constructor called" << std::endl;
	this->_type = type;
}

Animal::Animal( const Animal &animal ) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = animal;
}

Animal::~Animal( void ) {
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=( Animal const &animal ) {
	std::cout << "Animal assignation operator called" << std::endl;
	this->_type = animal.getType();
	return (*this);
}

std::string	Animal::getType( void ) const {
	return (this->_type);
}

std::string	Animal::setType( std::string type ) {
	this->_type = type;
	return (this->_type);
}

void	Animal::makeSound( void ) const {
	std::cout << "Animal sound" << std::endl;
}