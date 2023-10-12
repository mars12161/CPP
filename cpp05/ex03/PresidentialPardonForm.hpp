/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentalPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 08:56:22 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/07 09:55:56 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class PresidentialPardonForm: public AForm {
	private:
		PresidentialPardonForm();
		virtual void executeConcrete() const;
	public:
		PresidentialPardonForm(const std::string &target);
		~PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const &obj);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &obj);
};