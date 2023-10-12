/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:07:35 by mschaub           #+#    #+#             */
/*   Updated: 2023/07/17 08:40:17 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "AAnimal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main( void ) {
	int	n = 10;
	Animal *animals[n];

	for (int i = 0; i < n; i++) {
		if (i < (n/2))
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}

	for (int i = 0; i < n; i++)
		delete animals[i];

	Cat a;
	Cat b;
	std::cout << "Copying a cat" << std::endl;

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;

	//system("leaks Brain");
	return (0);
}
