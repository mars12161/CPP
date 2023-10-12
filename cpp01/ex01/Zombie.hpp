/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:47:07 by mschaub           #+#    #+#             */
/*   Updated: 2023/06/02 11:40:31 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class Zombie {
    private:
        std::string name;
    public:
        Zombie();
        ~Zombie();
        void    announce( void );
        void    setName( std::string name );
};

Zombie *zombieHorde( int N, std::string name );

#endif