/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:30:00 by ryabuki           #+#    #+#             */
/*   Updated: 2025/05/17 18:11:42 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"

int main() {
    try {
        // Create a bureaucrat with high rank to sign and execute all forms
        Bureaucrat boss("Boss", 1);
        std::cout << boss << std::endl;
        
        // Create an intern - the lowly worker who creates forms
        Intern someRandomIntern;
        
        // Test successful form creation
        std::cout << "\n--- Creating Shrubbery Creation Form ---" << std::endl;
        AForm* scf = someRandomIntern.makeForm("shrubbery creation", "garden");
        if (scf) {
            std::cout << *scf << std::endl;
            boss.signForm(*scf);
            boss.executeForm(*scf);
            delete scf;
        }
        
        std::cout << "\n--- Creating Robotomy Request Form ---" << std::endl;
        AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf) {
            std::cout << *rrf << std::endl;
            boss.signForm(*rrf);
            boss.executeForm(*rrf);
            delete rrf;
        }
        
        std::cout << "\n--- Creating Presidential Pardon Form ---" << std::endl;
        AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Zaphod");
        if (ppf) {
            std::cout << *ppf << std::endl;
            boss.signForm(*ppf);
            boss.executeForm(*ppf);
            delete ppf;
        }
        
        // Test form creation with invalid form name
        std::cout << "\n--- Creating Invalid Form ---" << std::endl;
        AForm* invalidForm = someRandomIntern.makeForm("coffee order", "office");
        if (invalidForm) {
            std::cout << *invalidForm << std::endl;
            boss.signForm(*invalidForm);
            boss.executeForm(*invalidForm);
            delete invalidForm;
        } else {
            std::cout << "Invalid form was not created, as expected" << std::endl;
        }
        
        // Test with a lower rank bureaucrat
        std::cout << "\n--- Testing with lower rank bureaucrat ---" << std::endl;
        Bureaucrat clerk("Clerk", 70);
        std::cout << clerk << std::endl;
        
        AForm* clerkForm = someRandomIntern.makeForm("shrubbery creation", "backyard");
        if (clerkForm) {
            std::cout << *clerkForm << std::endl;
            clerk.signForm(*clerkForm);  // Should be able to sign (grade 70 < 145)
            clerk.executeForm(*clerkForm); // Should be able to execute (grade 70 < 137)
            delete clerkForm;
        }
        
        AForm* clerkRobotomy = someRandomIntern.makeForm("robotomy request", "Computer");
        if (clerkRobotomy) {
            std::cout << *clerkRobotomy << std::endl;
            clerk.signForm(*clerkRobotomy);  // Should sign (grade 70 < 72)
            clerk.executeForm(*clerkRobotomy); // Should fail (grade 70 > 45)
            delete clerkRobotomy;
        }

    } catch (std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}
