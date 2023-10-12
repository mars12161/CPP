/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 08:57:38 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/07 10:02:37 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() {

}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("RobotomyRequestForm", target, 72, 45) {
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &obj): AForm(obj) {
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &obj) {
	std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
	if (this != &obj) {
		AForm::operator=(obj);
	}
	return (*this);
}

void RobotomyRequestForm::executeConcrete() const {
	std::cout << "Loud drilling noises" << std::endl;
	srand(time(NULL));
	if (rand() % 2 == 0)
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->_target << " robotomization failed" << std::endl;
}