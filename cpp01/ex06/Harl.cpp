/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:19:54 by mschaub           #+#    #+#             */
/*   Updated: 2023/06/12 17:44:18 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {

}

Harl::~Harl() {

}

void	Harl::debug( void ) {
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
	std::cout << std::endl;
}

void	Harl::info( void ) {
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
	std::cout << std::endl;
}

void	Harl::warning( void ) {
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
	std::cout << std::endl;
}

void	Harl::error( void ) {
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

static int get_level( std::string level ) {
	if (level == "DEBUG")
		return 0;
	else if (level == "INFO")
		return 1;
	else if (level == "WARNING")
		return 2;
	else if (level == "ERROR")
		return 3;
	return -1;
}

void	Harl::complain( std::string level ) {
	void (Harl::*debug)() = &Harl::debug;
	void (Harl::*info)() = &Harl::info;
	void (Harl::*warning)() = &Harl::warning;
	void (Harl::*error)() = &Harl::error;

	void (Harl::*complain[4])() = { debug, info, warning, error };

	switch (get_level(level))
	{
		case    0:
			(this->*complain[0])();
			// Fallthrough
		case    1:
			(this->*complain[1])();
			// Fallthrough
		case    2:
			(this->*complain[2])();
			// Fallthrough
		case    3:
			(this->*complain[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
