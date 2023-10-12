/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:07:40 by mschaub           #+#    #+#             */
/*   Updated: 2023/07/22 15:02:52 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) {
	std::cout << "Animal default constructor called" << std::endl;
	this->_type = "AAnimal";
}

AAnimal::AAnimal( std::string type ) {
	std::cout << "Animal type constructor called" << std::endl;
	this->_type = type;
}

AAnimal::AAnimal( const Animal &animal ) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = animal;
}

AAnimal::~AAnimal( void ) {
	std::cout << "Animal destructor called" << std::endl;
}

AAnimal &AAnimal::operator=( Animal const &animal ) {
	std::cout << "Animal assignation operator called" << std::endl;
	this->_type = animal.getType();
	return (*this);
}

std::string	AAnimal::getType( void ) const {
	return (this->_type);
}

std::string	AAnimal::setType( std::string type ) {
	this->_type = type;
	return (this->_type);
}

void	AAnimal::makeSound( void ) const {
	std::cout << "AAnimal sound" << std::endl;
}