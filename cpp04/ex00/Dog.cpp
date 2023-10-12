/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:07:54 by mschaub           #+#    #+#             */
/*   Updated: 2023/07/17 07:40:32 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	this->_type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog( const Dog &dog ) {
	*this = dog;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor was called" << std::endl;
}

Dog &Dog::operator=( const Dog &dog ) {
	std::cout << "Dog assignation operator called" << std::endl;
	this->_type = dog.getType();
	return (*this);
}

void Dog::makeSound() const {
	std::cout << "WOOF" << std::endl;
}
