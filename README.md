# CPP Module 05: Exception Handling

## Overview
This module explores C++ exception handling through the implementation of a bureaucratic system. It presents a practical approach to using try/catch blocks, custom exceptions, abstract classes, and design patterns in real-world programming scenarios.

## Projects

### ex00: Bureaucrat
- Introduction to exception handling with a simple Bureaucrat class
- Implementation of grade constraints (1-150) with custom exceptions
- Learning to throw and catch exceptions in appropriate contexts
- First exposure to the `std::exception` base class

### ex01: Form
- Extension of exception handling to form management
- Introduction of form signing requirements and permissions
- Development of relationships between classes (Bureaucrat and Form)
- Learning to handle multiple exception types in a hierarchy

### ex02: Abstract Forms
- Introduction to abstract classes with AForm
- Implementation of concrete form types with specific behaviors:
  - ShrubberyCreationForm: Creates ASCII tree in output files
  - RobotomyRequestForm: Simulates a robotomy procedure with success chance
  - PresidentialPardonForm: Issues presidential pardons
- Application of polymorphism for form execution
- Implementation of the template method pattern in abstract class design

### ex03: Intern
- Implementation of the Factory Design Pattern
- Dynamic creation of forms without explicit conditional logic
- Use of function pointers for flexible object creation
- Demonstration of effective memory management with raw pointers
- Creation of a clean, extensible system for adding new form types

## Key Technical Features
- **Custom Exception Classes**: Extending `std::exception` to create domain-specific exceptions
- **Function Pointers**: Using function pointers as factory methods
- **Polymorphism**: Leveraging virtual functions and abstract classes
- **RAII Principles**: Ensuring proper resource management
- **Factory Pattern**: Creating objects without specifying the exact class
- **Separation of Concerns**: Each class has a clear, distinct responsibility

## Design Highlights
- The system models a real-world bureaucratic process with appropriate constraints
- The Intern class demonstrates how to implement a factory without verbose switch/if-else statements
- Memory management is handled properly with appropriate deletion of dynamically allocated forms
- Error handling is comprehensive, catching and reporting all potential issues
- Code demonstrates proper encapsulation and information hiding principles

## Learning Outcomes
- Understanding when and how to use exception handling
- Recognizing the value of abstract classes in system design
- Implementing common design patterns to solve programming problems
- Managing memory safely in systems with dynamic object creation
- Designing class hierarchies that leverage polymorphism effectively
- Creating extensible systems that can adapt to new requirements

## Engineering Insights
- The project demonstrates how to balance flexibility and type safety
- Shows practical examples of design patterns in a constrained environment (C++98)
- Illustrates how to convert real-world processes into software models
- Provides examples of defensive programming with comprehensive error checking

This module offers a comprehensive introduction to exception handling while also touching on important design patterns and object-oriented principles that form the foundation of robust C++ software development.