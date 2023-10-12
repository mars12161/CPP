/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:30:32 by mschaub           #+#    #+#             */
/*   Updated: 2023/06/19 15:04:12 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
	public:
		ScavTrap();
		ScavTrap( std::string name );
		~ScavTrap();
		ScavTrap( const ScavTrap &scav );
		ScavTrap &operator=( const ScavTrap &scav );
		void	attack( const std::string &target );
		void	guardGate( void );
};

#endif