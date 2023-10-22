/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:46:08 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/21 07:48:30 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stdint.h>

class Serializer {
	public:
		struct Data {
			std::string s1;
			int n;
		};
		Serializer();
		Serializer(Serializer const &obj);
		~Serializer();
		Serializer &operator=(Serializer const &obj);
		static void setData(std::string s1, int n);
		static Data *getData();
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
	private:
		static Data *myData;
};