/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:53:41 by mschaub           #+#    #+#             */
/*   Updated: 2023/06/02 11:57:16 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {

}

Zombie::~Zombie() {
    std::cout << "Zombie " << this->name << " destroyed" << std::endl;
}

void    Zombie::setName(std::string name) {
    this->name = name;
}

void    Zombie::announce() {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
