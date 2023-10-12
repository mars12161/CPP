/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentalPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 09:36:30 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/07 10:16:04 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() {

}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm("PresidentialPardonForm", target, 25, 5) {
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &obj): AForm(obj) {
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &obj) {
	std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
	if (this != &obj)
		AForm::operator=(obj);
	return (*this);
}

void PresidentialPardonForm::executeConcrete() const {
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}


