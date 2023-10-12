/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:07:46 by mschaub           #+#    #+#             */
/*   Updated: 2023/07/22 15:02:29 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Brain.hpp"

class AAnimal {
	protected:
		std::string	_type;
	public:
		AAnimal();
		AAnimal( std::string type );
		AAnimal( const Animal &animal );
		AAnimal &operator=( const Animal &animal );
		virtual ~AAnimal();
		std::string	getType( void ) const;
		std::string setType( std::string type );
		virtual void	makeSound( void ) const;
};
