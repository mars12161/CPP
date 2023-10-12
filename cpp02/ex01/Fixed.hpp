/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 20:15:06 by mschaub           #+#    #+#             */
/*   Updated: 2023/06/16 11:37:11 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP_FIXED_HPP
# define CPP_FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int					_value;
		static const int	_bits = 8;
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &fixed);
		~Fixed();
		Fixed &operator=(const Fixed &fixed);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream & operator<<( std::ostream &o, Fixed const &i );


#endif
