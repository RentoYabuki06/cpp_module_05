/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:40:30 by ryabuki           #+#    #+#             */
/*   Updated: 2025/05/12 11:57:20 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form()
	: name("default")
	, isSigned(false)
	, gradeToSign(100)
	, gradeToExecute(100)
{}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
	: name(name)
	, isSigned(false)
	, gradeToSign(gradeToSign)
	, gradeToExecute(gradeToExecute)
{}

Form::Form(const Form& other)
	: name(other.name)
	, isSigned(other.isSigned)
	, gradeToSign(other.gradeToSign)
	, gradeToExecute(other.gradeToExecute)
{}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return *this;
}

Form::~Form() {}

const std::string&	Form::getName() const { return name; }
bool				Form::getIsSigined() const { return isSigned; }
int					Form::getGradeToSign() const { return gradeToSign; }
int					Form::getGradeToExecute() const { return gradeToExecute; }

void	Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "[----- Form grade too high ----]";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "[----- Form grade too low ----]";
}

std::ostream&	operator<<(std::ostream& os, const Form& f)
{
	os << f.getName() << ", requires grade " << f.getGradeToSign() << " to sign and " << f.getGradeToExecute() << " to execute. Signed: " << f.getIsSigined();
	return os;
}
