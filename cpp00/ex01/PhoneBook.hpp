/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:43:38 by mschaub           #+#    #+#             */
/*   Updated: 2023/05/31 21:48:23 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"
#include <iostream>
#include <string>

class PhoneBook
{
private:
    Contact contacts[8];
public:
    PhoneBook();
    ~PhoneBook();
    int     getIndex();
    void    show();
    void    addContact();
};

#endif