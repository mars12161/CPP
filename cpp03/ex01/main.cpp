/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:22:19 by mschaub           #+#    #+#             */
/*   Updated: 2023/06/19 15:22:19 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main( void ) {
	ScavTrap clap("Clap");
	ScavTrap scav("Scav");
	ScavTrap lav("Peter");
	clap.attack("target");
	clap.takeDamage(10);
	clap.beRepaired(10);
	return 0;
}