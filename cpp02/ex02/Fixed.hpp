/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 20:15:06 by mschaub           #+#    #+#             */
/*   Updated: 2023/06/16 15:08:53 by mschaub          ###   ########.fr       */
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
		Fixed &operator=( const Fixed &fixed );

		bool	operator>( const Fixed &fixed ) const;
		bool	operator<( const Fixed &fixed ) const;
		bool	operator>=( const Fixed &fixed ) const;
		bool	operator<=( const Fixed &fixed ) const;
		bool	operator==( const Fixed &fixed ) const;
		bool	operator!=( const Fixed &fixed ) const;

		Fixed	operator+( const Fixed &fixed ) const;
		Fixed	operator-( const Fixed &fixed ) const;
		Fixed	operator*( const Fixed &fixed ) const;
		Fixed	operator/( const Fixed &fixed ) const;

		Fixed	&operator++( void ); //prefix
		Fixed	&operator--( void ); //prefix
		Fixed	operator++( int ); //postfix
		Fixed	operator--( int ); //postfix

		static Fixed&	min( Fixed &a, Fixed &b );
		static Fixed&	max( Fixed &a, Fixed &b );

		static const Fixed&	min( const Fixed &a, const Fixed &b );
		static const Fixed&	max( const Fixed &a, const Fixed &b );


		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream & operator<<( std::ostream &o, Fixed const &i );


#endif
