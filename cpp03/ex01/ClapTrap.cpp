/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:22:33 by mschaub           #+#    #+#             */
/*   Updated: 2023/06/19 15:20:49 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->_name << " destroyed" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << this->_name << " created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clap) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = clap;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clap) {
	this->_name = clap._name;
	this->_hitPoints = clap._hitPoints;
	this->_energyPoints = clap._energyPoints;
	this->_attackDamage = clap._attackDamage;
	return *this;
}

void	ClapTrap::attack(const std::string &target) {
	if (this->_energyPoints == 0)
		std::cout << "Not enough energy points to attack" << std::endl;
	else {
		this->_energyPoints -= 1;
		std::cout << "ClapTrap " << this->_name << " attacks " << target
		<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints <= amount) {
		std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
		return;
	}
	std::cout << "ClapTrap got attacked and lost " << amount << " hit points" << std::endl;
	this->_hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energyPoints == 0)
		std::cout << "Not enough energy points to repair" << std::endl;
	else {
		this->_hitPoints += amount;
		this->_energyPoints -= 1;
		std::cout << "ClapTrap " << this->_name << " repairs itself and gets "
				  << this->_hitPoints << " hit points back" << std::endl;
	}
}