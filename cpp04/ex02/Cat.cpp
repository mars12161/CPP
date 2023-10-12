/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:08:45 by mschaub           #+#    #+#             */
/*   Updated: 2023/07/17 08:24:56 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat():_brain(new Brain()) {
	this->_type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat( const Cat &cat ):_brain(new Brain(*(cat._brain))) {
	*this = cat;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat() {
	delete _brain;
	std::cout << "Cat destructor was called" << std::endl;
}

Cat &Cat::operator=( const Cat &cat ) {
	std::cout << "Cat assignation operator called" << std::endl;
	this->_type = cat.getType();
	return (*this);
}

void	Cat::makeSound() const {
	std::cout << "MEAOW" << std::endl;
}
