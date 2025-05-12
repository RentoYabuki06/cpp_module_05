/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:53:47 by ryabuki           #+#    #+#             */
/*   Updated: 2025/05/12 11:59:53 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main() {
	std::cout << "=== 正常な署名 ===" << std::endl;
	try {
		Bureaucrat alice("Alice", 20);
		Form f1("NDA Form", 50, 10);
		std::cout << f1 << std::endl;

		alice.signForm(f1); // 成功するはず
		std::cout << f1 << std::endl;
	} catch (std::exception& e) {
		std::cerr << "例外: " << e.what() << std::endl;
	}

	std::cout << "\n=== 署名に失敗（グレードが低すぎる） ===" << std::endl;
	try {
		Bureaucrat bob("Bob", 140);
		Form f2("Security Clearance", 100, 50);
		std::cout << f2 << std::endl;

		bob.signForm(f2); // 失敗するはず
		std::cout << f2 << std::endl;
	} catch (std::exception& e) {
		std::cerr << "例外: " << e.what() << std::endl;
	}

	std::cout << "\n=== Formの生成に失敗（グレード不正） ===" << std::endl;
	try {
		Form invalidForm("Illegal Form", 0, 200); // 両方範囲外
	} catch (std::exception& e) {
		std::cerr << "例外: " << e.what() << std::endl;
	}

	std::cout << "\n=== Bureaucratの署名で再署名は無効 ===" << std::endl;
	try {
		Bureaucrat charlie("Charlie", 1);
		Form f3("Top Secret", 10, 1);
		charlie.signForm(f3);
		charlie.signForm(f3); // 2回目はすでに署名済み
	} catch (std::exception& e) {
		std::cerr << "例外: " << e.what() << std::endl;
	}

	std::cout << "\n=== グレード昇進による署名成功 ===" << std::endl;
	try {
		Bureaucrat dave("Dave", 120); // 初期グレードは署名条件を満たさない
		Form f4("Confidential Report", 100, 50);
		std::cout << f4 << std::endl;

		dave.signForm(f4); // ここでは失敗

		std::cout << "昇進中...\n";
		for (int i = 0; i < 25; ++i)
			dave.incrementGrade(); // グレードを25上げる（120→95）

		dave.signForm(f4); // 成功するはず
		std::cout << f4 << std::endl;

	} catch (std::exception& e) {
		std::cerr << "例外: " << e.what() << std::endl;
	}


	return 0;
}
