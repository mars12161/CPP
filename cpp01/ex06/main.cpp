/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:19:19 by mschaub           #+#    #+#             */
/*   Updated: 2023/06/12 13:25:49 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		return (std::cout << "Wrong amount of args\n", 0);
	}
	std::string input = argv[1];
	Harl        harl;

	harl.complain(input);

	return 0;
}
