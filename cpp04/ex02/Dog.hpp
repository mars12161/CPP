/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:07:58 by mschaub           #+#    #+#             */
/*   Updated: 2023/07/17 08:41:33 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"

class Dog: public Animal {
	public:
		Dog();
		Dog( std::string type );
		Dog( const Dog & src );
		Dog & operator=( const Dog & rhs);
		~Dog();
		void    makeSound( void ) const;
	private:
		Brain* _brain;
};