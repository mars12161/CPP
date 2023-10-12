/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 07:57:03 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/07 08:38:51 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	Bureaucrat bureaucrat1("Bureaucrat1", 1);
	Bureaucrat bureaucrat2("Bureaucrat2", 25);
	Form form1("Form A", 1, 1);
	Form form2("Form B", 150, 150);
	Form form3("Form C", 1, 150);
	Form form4("Form D", 150, 1);

	std::cout << bureaucrat1 << std::endl;
	std::cout << bureaucrat2 << std::endl;
	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;

	try {
		form1.beSigned(bureaucrat1);
		form3.beSigned(bureaucrat2);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		form1.beSigned(bureaucrat1);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form form5("Form E", 1000, 1);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;


}