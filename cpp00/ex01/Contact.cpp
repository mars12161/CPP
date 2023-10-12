/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:06:57 by mschaub           #+#    #+#             */
/*   Updated: 2023/05/31 21:55:38 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {};

Contact::~Contact() {};

void    Contact::setIndex(int index) {
    this->index =  index;
}

std::string Contact::getContact(std::string data) {
    bool    valid;
    std::string input;

    valid = true;
    input = "";
    while (valid)
    {
        std::cout << "Enter " << data << ": ";
        std::getline(std::cin, input);
        if (std::cin.good() && !input.empty())
            valid = false;
        else
        {
            std::cout << "Invalid input" << std::endl;
            std::cin.clear();
        }
    }
    return (input);
}

void    Contact::createContact() {
    this->firstName = getContact("first name");
    this->lastName = getContact("last name");
    this->nickName = getContact("nickname");
    this->phoneNumber = getContact("phone number");
    this->darkestSecret = getContact("darkest secret");
    std::cout << std::endl;
}

std::string Contact::cutStr(std::string str) {
    if (str.length() > 10)
        return str.substr(0,9).append(".");
    else
        return (str);
}

void    Contact::displayContact(int index) {
    if (this->firstName.empty() || this->lastName.empty() || this->nickName.empty())
        return ;
    std::cout << std::setw(10) << index << "|";
    std::cout << std::setw(10) << cutStr(this->firstName) << "|";
    std::cout << std::setw(10) << cutStr(this->lastName) << "|";
    std::cout << std::setw(10) << cutStr(this->nickName) << "|";
    std::cout << std::endl << std::endl;
}

