/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 15:40:21 by mschaub           #+#    #+#             */
/*   Updated: 2023/07/17 07:56:15 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

 WrongCat::WrongCat() {
	 std::cout << "WrongCat default constructor called" << std::endl;
	 this->_type = "WrongCat";
 }

 WrongCat::WrongCat( const WrongCat &cat ) {
	 *this = cat;
	 std::cout << "WrongCat copy constructor called" << std::endl;
 }

 WrongCat::~WrongCat() {
	 std::cout << "WrongCat destructor called" << std::endl;
 }

 WrongCat &WrongCat::operator=( const WrongCat &cat ) {
	 std::cout << "WrongCat assignation operator called" << std::endl;
	 this->_type = cat.getType();
	 return (*this);
 }

void WrongCat::makeSound() const {
	std::cout << "Wrong MEAOW" << std::endl;
}