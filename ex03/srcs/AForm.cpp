/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:40:30 by ryabuki           #+#    #+#             */
/*   Updated: 2025/05/12 13:11:02 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

AForm::AForm()
	: name("default")
	, isSigned(false)
	, gradeToSign(100)
	, gradeToExecute(100)
{}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
	: name(name)
	, isSigned(false)
	, gradeToSign(gradeToSign)
	, gradeToExecute(gradeToExecute)
{}

AForm::AForm(const AForm& other)
	: name(other.name)
	, isSigned(other.isSigned)
	, gradeToSign(other.gradeToSign)
	, gradeToExecute(other.gradeToExecute)
{}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return *this;
}

AForm::~AForm() {}

const std::string&	AForm::getName() const { return name; }
bool				AForm::getIsSigned() const { return isSigned; }
int					AForm::getGradeToSign() const { return gradeToSign; }
int					AForm::getGradeToExecute() const { return gradeToExecute; }

void	AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > gradeToSign)
		throw SignGradeTooHighException();
	isSigned = true;
}

void AForm::checkExecutable(const Bureaucrat& executor) const
{
	if (!isSigned)
		throw NotSignedException();
	if (executor.getGrade() > gradeToExecute)
		throw ExecGradeTooHighException();
}

const char* AForm::SignGradeTooHighException::what() const throw()
{
	return "[AForm] Grade too high to be signed.";
}

const char* AForm::SignGradeTooLowException::what() const throw()
{
	return "[AForm] Grade too low to be signed.";
}

const char* AForm::ExecGradeTooHighException::what() const throw()
{
	return "[AForm] Grade too high to be executed.";
}

const char* AForm::ExecGradeTooLowException::what() const throw()
{
	return "[AForm] Grade too low to be executed.";
}

const char* AForm::NotSignedException::what() const throw()
{
	return "[AForm] is not signed yet.";
}

std::ostream&	operator<<(std::ostream& os, const AForm& f)
{
	os << f.getName() << ", requires grade " << f.getGradeToSign() << " to sign and " << f.getGradeToExecute() << " to execute. Signed: " << f.getIsSigned();
	return os;
}
