/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:52:58 by mschaub           #+#    #+#             */
/*   Updated: 2023/06/02 09:50:41 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <iomanip>
#include <string>

class Contact
{
private:
    int index;
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;
public:
    Contact();
    ~Contact();
    std::string getContact(std::string data);
    void        createContact();
    void        displayContact(int index);
    void        setIndex(int index);
    std::string cutStr(std::string str);
};

#endif