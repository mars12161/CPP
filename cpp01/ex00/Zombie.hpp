/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:47:07 by mschaub           #+#    #+#             */
/*   Updated: 2023/03/17 16:03:09 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class Zombie {
    private:
        std::string name;
    public:
        Zombie( std::string name );
        ~Zombie();
        void    announce( void );
        void    randomChump( std::string name );
        Zombie  *newZombie( std::string name );
};

Zombie	*newZombie( std::string name );
void	randomChump( std::string name );

#endif