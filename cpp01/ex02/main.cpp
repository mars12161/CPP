/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:52:19 by mschaub           #+#    #+#             */
/*   Updated: 2023/06/02 13:01:10 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main( void ) {
	std::string brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout << &brain << " -- " << brain << std::endl;
	std::cout << stringPTR << " -- " << *stringPTR << std::endl;
	std::cout << &stringREF << " -- " << stringREF << std::endl;
}
