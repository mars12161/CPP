/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:07:46 by mschaub           #+#    #+#             */
/*   Updated: 2023/07/17 08:19:35 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Brain.hpp"

class Animal {
	protected:
		std::string	_type;
	public:
		Animal();
		Animal( std::string type );
		Animal( const Animal &animal );
		Animal &operator=( const Animal &animal );
		virtual ~Animal();
		std::string	getType( void ) const;
		std::string setType( std::string type );
		virtual void	makeSound( void ) const;
};
