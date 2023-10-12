/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 07:36:21 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/07 10:21:16 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	protected:
		std::string const _name;
		std::string const _target;
		bool _signed;
		int const _gradeToSign;
		int const _gradeToExecute;
		AForm();
		virtual void executeConcrete() const = 0;
	public:
		AForm(const std::string &name, const std::string &target, int gradeToSign, int gradeToExecute);
		virtual ~AForm();
		AForm(AForm const &obj);
		AForm &operator=(AForm const &obj);
		std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(Bureaucrat &bureaucrat);
		void execute(Bureaucrat const &executor) const;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class FormAlreadySignedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class CannotExecuteException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &form);