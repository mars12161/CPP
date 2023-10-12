/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 09:40:53 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/07 12:02:25 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main(void) {
	Intern intern;
	AForm *form1;
	AForm *form2;
	AForm *form3;

	Bureaucrat bureaucrat1("Bureaucrat1", 1);

	try {
		form1 = intern.MakeForm("shrubbery creation", "Bender");
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		form2 = intern.MakeForm("presidential pardon", "Donald");
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << *form1 << std::endl;
	std::cout << *form2 << std::endl;

	try {
		form3 = intern.MakeForm("random stuff", "Trump");
		delete form3;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		bureaucrat1.signForm(*form1);
		bureaucrat1.executeForm(*form1);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	delete form1;
	delete form2;
}
