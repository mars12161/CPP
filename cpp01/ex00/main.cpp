/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:18:43 by mschaub           #+#    #+#             */
/*   Updated: 2023/03/17 15:18:44 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void ) {
	std::string name;

	std::cout << "Zombie on stack" << std::endl;
	std::cout << "Enter name of zombie 1: " << std::endl;
	std::cin >> name;

	Zombie zombie1(name);
	zombie1.announce();

	std::cout << "Zombie on heap" << std::endl;
	std::cout << "Enter name of zombie 2: " << :: std::endl;
	std::cin >> name;

	Zombie *zombie2 = newZombie(name);
	zombie2->announce();
	delete zombie2;
	std::cout << "Using randomChump" << std::endl;
	randomChump("Peter");
	return 0;
}
