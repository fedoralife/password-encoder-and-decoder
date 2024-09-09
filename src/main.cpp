#include <iostream>
#include <string>
#include "hash.h"

void option() {
    hash hash_obj;
    std::string original;
    std::string name;
    int choice;

    // Get user input for the string and name
    while (true) {
        std::cout << "\nChoose an operation:\n";
        std::cout << "1. Register a new User\n";
        std::cout << "2. Login a User\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Ignore the newline character after choice input

        if (choice == 1) {
            std::cout << "Enter your name: ";
            std::getline(std::cin, name);
            std::cout << "Enter your original string: ";
            std::getline(std::cin, original);
            hash_obj.Encode(original, name);
            std::cout << "User registered successfully.\n";
        } else if (choice == 2) {
            std::cout << "Enter your name: ";
            std::getline(std::cin, name);
            if (hash_obj.Login(name)) { // Assuming Login method checks for the existence of the user
                std::cout << "Enter original: ";
                std::getline(std::cin, original);
                std::string decoded = hash_obj.Decode(name);
                if (original == decoded) {
                    std::cout << "Login successful.\n";
                } else {
                    std::cout << "Incorrect original.\n";
                }
            } else {
                std::cout << "User not found.\n";
            }
        } else if (choice == 3) {
            break;
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

int main() {
    option();
    return 0;
}