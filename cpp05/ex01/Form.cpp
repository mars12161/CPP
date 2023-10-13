/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 07:38:20 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/13 08:19:35 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("Default"), _signed(false), _gradeToSign(0), _gradeToExecute(0) {
	std::cout << "Default constructor" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute): _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	std::cout << "Custom constructor: " << name << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::~Form() {
	std::cout << "Destructor of " << this->_name << std::endl;
}

Form::Form(Form const &obj): _name(obj.getName()), _signed(obj.getSigned()), _gradeToSign(obj.getGradeToSign()), _gradeToExecute(obj.getGradeToExecute()) {
	std::cout << "Copy constructor" << std::endl;
}

Form &Form::operator=(Form const &obj) {
	std::cout << "Assignment operator" << std::endl;
	if (this != &obj) {
	}
	return (*this);
}

std::string Form::getName() const {
	return (_name);
}

bool Form::getSigned() const {
	return (_signed);
}

int Form::getGradeToSign() const {
	return (_gradeToSign);
}

int Form::getGradeToExecute() const {
	return (_gradeToExecute);
}

void Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	else if (_signed)
		throw Form::FormAlreadySignedException();
	else {
		_signed = true;
		std::cout << bureaucrat.getName() << " signs " << _name << std::endl;
	}
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}

const char *Form::FormAlreadySignedException::what() const throw() {
	return ("Form already signed");
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
	out << "Form name: " << form.getName() << std::endl;
	out << "Form signed?: " << form.getSigned() << std::endl;
	out << "Grade needed to sign: " << form.getGradeToSign() << std::endl;
	out << "Grade needed to execute: " << form.getGradeToExecute() << std::endl;
	return (out);
}