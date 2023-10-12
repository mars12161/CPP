/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:18:13 by mschaub           #+#    #+#             */
/*   Updated: 2023/06/02 11:59:20 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void ) {
	int amount;
	std::string name;

	std::cout << "Enter amount of zombies:" << std::endl;
	std::cin >> amount;

	std::cout << "Enter name of zombies:" << std::endl;
	std::cin >> name;
	Zombie *zombies = zombieHorde(amount, name);
	for (int i = 0; i < amount; i++)
		zombies[i].announce();
	delete [] zombies;
	return 0;
}
