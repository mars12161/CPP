/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:03:54 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/07 12:00:40 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const std::string Intern::_formNames[3] = {
	"presidential pardon",
	"robotomy request",
	"shrubbery creation"
};

const FormFunction Intern::_formFunctions[3] = {
	&Intern::makePardon,
	&Intern::makeRobotomy,
	&Intern::makeShrubbery
};

Intern::Intern() {

}

Intern::Intern(Intern const &obj) {
	*this = obj;
}

Intern &Intern::operator=(Intern const &obj) {
	(void)obj;
	return (*this);
}

Intern::~Intern() {}

AForm * Intern::MakeForm(std::string const &formName, std::string const &target) const{
	for (int i = 0; i < 3; i++) {
		if (formName == _formNames[i]) {
			return ((this->*_formFunctions[i])(target));
		}
	}
	throw Intern::CannotCreateForm();
}

AForm *Intern::makePardon(std::string const &target) const {
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeRobotomy(std::string const &target) const {
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makeShrubbery(std::string const &target) const {
	return (new ShrubberyCreationForm(target));
}

const char *Intern::CannotCreateForm::what() const throw() {
	return ("Cannot create form");
}
