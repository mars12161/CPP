/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:20:19 by mschaub           #+#    #+#             */
/*   Updated: 2023/06/12 13:31:18 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP_HARL_HPP
# define CPP_HARL_HPP

#include <iostream>
#include <string>

class Harl {
	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
	public:
		Harl();
		~Harl();
		void	complain( std::string level );
};

#endif
