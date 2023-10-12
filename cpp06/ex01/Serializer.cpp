/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:51:48 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/09 15:28:33 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


Serializer::Data *Serializer::myData = NULL;

Serializer::Serializer() {
	myData = new Data;
}

Serializer::Serializer(Serializer const &obj) {
	*this = obj;
}

Serializer::~Serializer() {
	delete myData;
}

Serializer &Serializer::operator=(const Serializer &obj) {
	myData = obj.myData;
	return *this;
}

void Serializer::setData(std::string s1, int n) {
	myData->s1 = s1;
	myData->n = n;
}

Serializer::Data *Serializer::getData() {
	return myData;
}

uintptr_t Serializer::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Serializer::Data *Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}
