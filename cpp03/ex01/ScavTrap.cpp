/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:30:38 by mschaub           #+#    #+#             */
/*   Updated: 2023/06/26 08:05:42 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap() {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap( std::string name ): ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap Name constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->_name << " destroyed" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &scav ): ClapTrap(scav) {
	this->_hitPoints = scav._hitPoints;
	this->_energyPoints = scav._energyPoints;
	this->_attackDamage = scav._attackDamage;
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=( const ScavTrap &scav ) {
	std::cout << "ScavTrap assignation operator called" << std::endl;
	this->_name = scav._name;
	this->_hitPoints = scav._hitPoints;
	this->_energyPoints = scav._energyPoints;
	this->_attackDamage = scav._attackDamage;
	return *this;
}

void	ScavTrap::attack( const std::string &target ) {
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate( void ) {
	std::cout << "ScavTrap " << this->_name << " has entered in Gate keeper mode" << std::endl;
}