/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:30:31 by mschaub           #+#    #+#             */
/*   Updated: 2023/06/25 13:21:54 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
	public:
		FragTrap();
		FragTrap( std::string name );
		~FragTrap();
		FragTrap( const FragTrap &frag );
		FragTrap &operator=( const FragTrap &frag );
		void highFivesGuys( void );
};
#endif
