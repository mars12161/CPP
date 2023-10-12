/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 15:40:15 by mschaub           #+#    #+#             */
/*   Updated: 2023/07/17 07:39:42 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal default constructor called" << std::endl;
	this->_type = "WrongAnimal";
}

WrongAnimal::WrongAnimal( std::string type) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	this->_type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal &animal) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = animal;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &animal) {
	std::cout << "WrongAnimal assignation operator called" << std::endl;
	this->_type = animal.getType();
	return (*this);
}

std::string WrongAnimal::getType( void ) const {
	return (this->_type);
}

std::string WrongAnimal::setType(std::string type) {
	this->_type = type;
	return (this->_type);
}

void	WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal sound" << std::endl;
}
