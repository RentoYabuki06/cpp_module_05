/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:29:13 by ryabuki           #+#    #+#             */
/*   Updated: 2025/05/12 10:51:28 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat alice("Alice", 0); // エラー
	} catch (std::exception& e) {
		std::cerr << "Failed to create Alice: " << e.what() << std::endl;
	}

	try {
		Bureaucrat bob("Bob", 2);
		std::cout << bob << std::endl;
		bob.incrementGrade();
		std::cout << "After increment: " << bob << std::endl;
		bob.incrementGrade(); // エラー（1 → 0）
	} catch (std::exception& e) {
		std::cerr << "Error while modifying Bob: " << e.what() << std::endl;
	}

	try {
		Bureaucrat charlie("Charlie", 149);
		std::cout << charlie << std::endl;
		charlie.decrementGrade();
		std::cout << "After decrement: " << charlie << std::endl;
		charlie.decrementGrade(); // エラー（150 → 151）
	} catch (std::exception& e) {
		std::cerr << "Error while modifying Charlie: " << e.what() << std::endl;
	}

	return 0;
}
