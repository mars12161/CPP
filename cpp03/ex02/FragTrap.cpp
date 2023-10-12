/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:30:36 by mschaub           #+#    #+#             */
/*   Updated: 2023/06/26 08:08:34 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap() {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap( std::string name ): ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap name constructor called" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->_name << " destroyed" << std::endl;
}

FragTrap::FragTrap( const FragTrap &frag ): ClapTrap(frag) {
	this->_hitPoints = frag._hitPoints;
	this->_energyPoints = frag._hitPoints;
	this->_attackDamage = frag._attackDamage;
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=( const FragTrap &frag ) {
	this->_name = frag._name;
	this->_hitPoints = frag._hitPoints;
	this->_energyPoints = frag._energyPoints;
	this->_attackDamage = frag._attackDamage;
	return (*this);
}

void FragTrap::highFivesGuys( void ) {
	std::cout << "FragTrap " << this->_name << " wants to high five" << std::endl;
}