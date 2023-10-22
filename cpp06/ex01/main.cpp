/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:04:03 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/21 07:48:00 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void) {
	Serializer s;

	s.setData("Peter", 43567);
	std::cout << "s1: " << s.getData()->s1 << std::endl;
	std::cout << "n: " << s.getData()->n << std::endl;

	Serializer::Data *original = s.getData();
	std::cout << "original: " << original << std::endl;

	uintptr_t raw = Serializer::serialize(s.getData());
	std::cout << "serialized: " << raw << std::endl;

	Serializer::Data *deserialized = Serializer::deserialize(raw);
	std::cout << "deserialized: " << deserialized << std::endl;

	return 0;
}
