/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 07:47:00 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/13 08:07:33 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {

	Bureaucrat peter("Peter", 125);
	std::cout << peter << std::endl;
	try {
		Bureaucrat bureaucrat("Bob", 0);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat bureaucrat("Foo", 151);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

    try {
        peter.incrementGrade();
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        peter.decrementGrade();
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << peter << std::endl;

    Bureaucrat bob("Bob", 1);
    std::cout << peter << std::endl;

    try {
        bob.incrementGrade();
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << bob << std::endl;

}