/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:17:33 by ryabuki           #+#    #+#             */
/*   Updated: 2025/05/12 12:25:18 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	name;
	bool				isSigned;
	const int 			gradeToSign;
	const int			gradeToExecute;
protected:
	AForm();
public:
	AForm(const std::string& name, int gradeToSign, int gradeToExecute);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

	const std::string&	getName() const;
	bool				getIsSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;

	void	beSigned(const Bureaucrat& b);
	void	checkExecutable(const Bureaucrat& executer) const;
	virtual void	execute(const Bureaucrat& executer) const = 0;

	class SignGradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw();
	};
	class SignGradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw();
	};
	class ExecGradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw();
	};
	class ExecGradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw();
	};
	class NotSignedException : public std::exception
	{
	public:
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
