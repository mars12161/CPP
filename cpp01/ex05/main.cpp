/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:19:19 by mschaub           #+#    #+#             */
/*   Updated: 2023/06/09 10:36:43 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main( void ) {
	std::string	input;
	Harl		harl;

	while (input.compare("exit")) {
		std::cout << "Enter a level: " << std::endl;
		std::cin >> input;
		harl.complain(input);
	}
	return (0);
}
