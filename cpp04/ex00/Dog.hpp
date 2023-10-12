/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:07:58 by mschaub           #+#    #+#             */
/*   Updated: 2023/06/26 10:57:31 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog: public Animal {
	public:
		Dog();
		Dog( std::string type );
		Dog( const Dog & src );
		Dog & operator=( const Dog & rhs);
		~Dog();
		void    makeSound( void ) const;
};