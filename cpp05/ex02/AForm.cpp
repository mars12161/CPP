/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 07:38:20 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/07 10:37:18 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _name("Default"), _signed(false), _gradeToSign(0), _gradeToExecute(0) {
	std::cout << "Default constructor" << std::endl;
}

AForm::AForm(const std::string &name, const std::string &target, int gradeToSign, int gradeToExecute): _name(name), _target(target), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	std::cout << "Custom constructor" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm() {
	std::cout << "AForm Destructor" << std::endl;
}

AForm::AForm(AForm const &obj): _name(obj.getName()), _signed(obj.getSigned()), _gradeToSign(obj.getGradeToSign()), _gradeToExecute(obj.getGradeToExecute()) {
	std::cout << "Copy constructor" << std::endl;
}

AForm &AForm::operator=(AForm const &obj) {
	std::cout << "Assignment operator" << std::endl;
	if (this != &obj) {
	}
	return (*this);
}

std::string AForm::getName() const {
	return (_name);
}

bool AForm::getSigned() const {
	return (_signed);
}

int AForm::getGradeToSign() const {
	return (_gradeToSign);
}

int AForm::getGradeToExecute() const {
	return (_gradeToExecute);
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	else if (_signed)
		throw AForm::FormAlreadySignedException();
	else {
		_signed = true;
	}
}

void AForm::execute(Bureaucrat const &executor) const {
	if (!_signed)
		throw AForm::CannotExecuteException();
	if (executor.getGrade() > _gradeToExecute)
		throw AForm::GradeTooLowException();
	executeConcrete();
}

const char *AForm::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}

const char *AForm::FormAlreadySignedException::what() const throw() {
	return ("Form already signed");
}

const char *AForm::CannotExecuteException::what() const throw() {
	return ("Cannot execute unsigned form");
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {
	out << "Form name: " << form.getName() << std::endl;
	out << "Form signed?: " << form.getSigned() << std::endl;
	out << "Grade needed to sign: " << form.getGradeToSign() << std::endl;
	out << "Grade needed to execute: " << form.getGradeToExecute() << std::endl;
	return (out);
}