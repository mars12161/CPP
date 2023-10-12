/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:08:50 by mschaub           #+#    #+#             */
/*   Updated: 2023/07/17 08:43:03 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"

class Cat : public Animal {

	public:
		Cat();
		Cat( Cat const &cat );
		~Cat();
		Cat &operator=( Cat const &cat );
		void makeSound() const;

	private:
		Brain* _brain;
};
