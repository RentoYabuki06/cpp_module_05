/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:27:58 by ryabuki           #+#    #+#             */
/*   Updated: 2025/05/12 13:09:56 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
	const std::string target;
	ShrubberyCreationForm();
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	public:
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm(const std::string& target);
	virtual ~ShrubberyCreationForm();

	void	execute(const Bureaucrat& executer) const;
};

#endif
