/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:22:25 by mschaub           #+#    #+#             */
/*   Updated: 2023/06/19 15:02:28 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
	private:
		std::string _name;
		unsigned int			_hitPoints;
		unsigned int			_energyPoints;
		unsigned int			_attackDamage;
	public:
		ClapTrap();
		ClapTrap( std::string name );
		~ClapTrap();
		ClapTrap( const ClapTrap &clap );
		ClapTrap &operator=( const ClapTrap &clap );
		void	attack( const std::string &target );
		void	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amount );

};

#endif