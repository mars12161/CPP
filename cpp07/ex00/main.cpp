/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:05:35 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/10 16:37:11 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main(void) {
	int a = 10;
	int b = 15;

	std::cout << "a = " << a << ", b = " << b << std::endl;

	swap(a, b);

	std::cout << "a = " << a << ", b = " << b << std::endl;

	std::cout << "min(a, b) = " << min(a, b) << std::endl;

	std::cout << "max(a, b) = " << max(a, b) << std::endl;

	int c = 10;
	int d = 10;

	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << min(c, d) << std::endl;
	std::cout << "max(c, d) = " << max(c, d) << std::endl;

	std::string e = "chainz";
	std::string f = "chainzzz";

	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min(e, f) = " << min(e, f) << std::endl;
	std::cout << "max(e, f) = " << max(e, f) << std::endl;
	std::cout << "swap(e, f): ";
	swap(e, f);
	std::cout << "e = " << e << ", f = " << f << std::endl;

	char g = 'p';
	char h = 'f';

	std::cout << "g = " << g << ", h = " << h << std::endl;
	std::cout << "min(g, h) = " << min(g, h) << std::endl;
	std::cout << "max(g, h) = " << max(g, h) << std::endl;
	std::cout << "swap(g, h): ";
	swap(g, h);
	std::cout << "g = " << g << ", h = " << h << std::endl;

	int i = 2;
	int j = 3;
	::swap( i, j );
	std::cout << "i = " << i << ", j = " << j << std::endl;
	std::cout << "min( i, j ) = " << ::min( i, j ) << std::endl;
	std::cout << "max( i, j ) = " << ::max( i, j ) << std::endl;
	std::string x = "chaine1";
	std::string y = "chaine2";
	::swap(x, y);
	std::cout << "x = " << x << ", y = " << y << std::endl;
	std::cout << "min( x, y ) = " << ::min( x, y ) << std::endl;
	std::cout << "max( x, y ) = " << ::max( x, y ) << std::endl;

}