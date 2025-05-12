/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:45:16 by ryabuki           #+#    #+#             */
/*   Updated: 2025/05/12 13:10:06 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class PresidentialPardonForm : public AForm
{
private:
	const std::string target;
	PresidentialPardonForm();
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	public:
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm(const std::string& target);
	virtual ~PresidentialPardonForm();

	void	execute(const Bureaucrat& executer) const;
};

#endif
