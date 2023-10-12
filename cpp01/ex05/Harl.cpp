/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:19:54 by mschaub           #+#    #+#             */
/*   Updated: 2023/06/09 10:50:03 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {

}

Harl::~Harl() {

}

void	Harl::debug( void ) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void	Harl::info( void ) {
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void	Harl::warning( void ) {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void	Harl::error( void ) {
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void	Harl::complain( std::string level ) {
	t_func	funcs[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	while (i < 4 && levels[i].compare(level))
		i++;
	if (i < 4)
		(this->*funcs[i])();
}