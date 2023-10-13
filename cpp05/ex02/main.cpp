/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 09:40:53 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/13 08:33:30 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {
	Bureaucrat b1("b1", 142);
	Bureaucrat b2("b2", 30);
	Bureaucrat b3("b3", 50);
	Bureaucrat b4("b4", 1);

	ShrubberyCreationForm s1("home");
	std::cout << s1 << std::endl;
	RobotomyRequestForm r1("Freddy");
	std::cout << r1 << std::endl;
	PresidentialPardonForm p1("Donald");
	std::cout << p1 << std::endl;

    try {
        b1.executeForm(s1);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

	try {
		b1.signForm(s1);
		b1.executeForm(s1);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		b3.signForm(s1);
		b3.executeForm(s1);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		b2.signForm(r1);
		b2.executeForm(r1);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		b4.signForm(p1);
		b4.executeForm(p1);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
