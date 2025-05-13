/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:45:11 by ryabuki           #+#    #+#             */
/*   Updated: 2025/05/12 13:10:01 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
private:
	const std::string target;
	RobotomyRequestForm();
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	public:
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm(const std::string& target);
	virtual ~RobotomyRequestForm();

	void	execute(const Bureaucrat& executer) const;
};

#endif
