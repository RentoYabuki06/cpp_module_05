/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:20:00 by ryabuki           #+#    #+#             */
/*   Updated: 2025/05/17 18:12:11 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
}

Intern::~Intern() {}

AForm* createShrubbery(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

AForm* createRobotomy(const std::string& target) {
	return new RobotomyRequestForm(target);
}

AForm* createPresidential(const std::string& target) {
	return new PresidentialPardonForm(target);
}


AForm*	Intern::makeForm(const std::string& name, const std::string& target)
{
	const size_t n = 3;
	std::string formNames[n] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (*formCreators[n])(const std::string&) = {&createShrubbery, &createRobotomy, &createPresidential};

	for (size_t i = 0; i < n; i++)
	{
		if (name == formNames[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return formCreators[i](target);
		}
	}
	std::cout << "No form matches the provided name!" << std::endl;
	return NULL;
}
