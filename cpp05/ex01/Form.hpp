/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 07:36:21 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/09 08:56:10 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
	std::string const _name;
	bool _signed;
	int const _gradeToSign;
	int const _gradeToExecute;
	Form();
public:
	Form(std::string name, int gradeToSign, int gradeToExecute);
	~Form();
	Form(Form const &obj);
	Form &operator=(Form const &obj);
	std::string getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(Bureaucrat &bureaucrat);

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
};

std::ostream &operator<<(std::ostream &out, const Form &form);