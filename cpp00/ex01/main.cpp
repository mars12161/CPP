/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:11:25 by mschaub           #+#    #+#             */
/*   Updated: 2023/05/31 21:40:45 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main() {
    std::string input;
    PhoneBook phoneBook;

    while (42)
    {
        std::cout << "Enter one of the following commands:" << std::endl;
        std::cout << "ADD: to add a contact" << std::endl;
        std::cout << "SEARCH: to search for a specific contact" << std::endl;
        std::cout << "EXIT: to exit the program" << std::endl;
        std::getline(std::cin, input);
        if (input == "EXIT")
            break;
        else if (input == "ADD")
            phoneBook.addContact();
        else if (input == "SEARCH") {
            phoneBook.show();
            std::cin.ignore();
        }
        else
            std::cout << "Invalid input" << std::endl;
    }
    return 0;
}
