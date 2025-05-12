/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:53:47 by ryabuki           #+#    #+#             */
/*   Updated: 2025/05/12 13:03:38 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main() {
	try {
		Bureaucrat boss("Boss", 1);

		std::cout << "\n--- ShrubberyCreationForm ---" << std::endl;
		ShrubberyCreationForm shrub("garden");
		std::cout << shrub << std::endl;

		try {
			boss.executeForm(shrub); // 署名前 → 例外
		} catch (std::exception& e) {
			std::cout << "Expected failure: " << e.what() << std::endl;
		}

		boss.signForm(shrub);
		boss.executeForm(shrub); // 成功
		std::cout << shrub << std::endl;

		std::cout << "\n[Copy test] コピー & 代入" << std::endl;
		ShrubberyCreationForm shrubCopy(shrub);
		ShrubberyCreationForm shrubAssigned = shrub;
		boss.executeForm(shrubCopy);
		boss.executeForm(shrubAssigned);

		std::cout << "\n--- RobotomyRequestForm ---" << std::endl;
		RobotomyRequestForm robo("Bender");
		boss.signForm(robo);
		for (int i = 0; i < 3; ++i)
			boss.executeForm(robo); // ランダム成功/失敗

		std::cout << "\n--- PresidentialPardonForm ---" << std::endl;
		PresidentialPardonForm pardon("Ford Prefect");
		boss.signForm(pardon);
		boss.executeForm(pardon);

		std::cout << "\n[Copy test] Robotomy コピー & 代入" << std::endl;
		RobotomyRequestForm roboCopy(robo);
		RobotomyRequestForm roboAssigned = robo;
		boss.executeForm(roboCopy);
		boss.executeForm(roboAssigned);

		std::cout << "\n[Copy test] Pardon コピー & 代入" << std::endl;
		PresidentialPardonForm pardonCopy(pardon);
		PresidentialPardonForm pardonAssigned = pardon;
		boss.executeForm(pardonCopy);
		boss.executeForm(pardonAssigned);

	} catch (std::exception& e) {
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	return 0;
}
