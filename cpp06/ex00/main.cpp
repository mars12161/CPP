/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 10:47:06 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/08 13:46:13 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Wrong number of arguments" << std::endl;
		return 1;
	}
	else if (argv[1][0] == '\0') {
		std::cout << "Empty string" << std::endl;
		return 1;
	}
	ScalarConverter sc;
	ScalarConverter::setStr(argv[1]);
	if (!ScalarConverter::isLiteral()) {
		std::cout << "Wrong literal" << std::endl;
		return 1;
	}
	ScalarConverter::convert();
	std::cout << sc;
	return 0;
}
