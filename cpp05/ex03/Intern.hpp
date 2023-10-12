/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:53:29 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/07 12:00:50 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern;

typedef AForm* (Intern::*FormFunction)(std::string const &) const;

class Intern {
	public:
		Intern();
		Intern(Intern const &obj);
		Intern &operator=(Intern const &obj);
		~Intern();
		AForm * MakeForm(std::string const &formName, std::string const &target) const;

		class CannotCreateForm : public std::exception {
			public:
				virtual const char *what() const throw();
		};
	private:
		AForm *makePardon(std::string const &target) const;
		AForm *makeRobotomy(std::string const &target) const;
		AForm *makeShrubbery(std::string const &target) const;
		static const std::string _formNames[3];
		static const FormFunction _formFunctions[3];
};