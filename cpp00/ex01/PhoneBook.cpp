/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:11:01 by mschaub           #+#    #+#             */
/*   Updated: 2023/05/31 21:54:28 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook() {
    std::cout << "PhoneBook created" << std::endl;
}

PhoneBook::~PhoneBook() {
    std::cout << "PhoneBook destroyed" << std::endl;
}

void    PhoneBook::addContact() {
    static int  i;
    this->contacts[i % 8].createContact();
    this->contacts[i % 8].setIndex(i % 8);
    i++;
}

int PhoneBook::getIndex() {
    bool valid;
    int input;

    valid = false;
    input = -1;
    while (!valid)
    {
        std::cout << "Enter index of contact you want to display: " << std::endl;
        std::cin >> input;
        std::cout << std::endl;
        if (std::cin.good() && (input >= 0 && input < 8))
            valid = true;
        else {
            std::cout << "Invalid input" << std::endl;
            std::cin.clear();
        }
    }
    return (input);
}

void    PhoneBook::show() {
    int index;

    index = getIndex();
    this->contacts[index].displayContact(index);
}