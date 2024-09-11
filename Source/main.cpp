#include <iostream>
#include <string>


#include "hash.h"

void option();

int main() {
    option();
    system("clear");
    std :: cout << "Thank you for using this software\n";
    system("sleep 1");
    system("clear");
    return 0;
}

void option() {
    hash hash_obj;
    std::string password;
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
        std::cin.ignore(); 

        if (choice == 1) {
            std::cout << "Enter your name: ";
            std::getline(std::cin, name);
            std::cout << "Enter your password ";
            std::getline(std::cin, password);
            hash_obj.Encode(password, name);
            std::cout << "User registered successfully.\n";
            system("sleep 1");
            system("clear");
        } else if (choice == 2) {
            std::cout << "Enter your name: ";
            std::getline(std::cin, name);
            if (hash_obj.Login(name)) { 
                std::cout << "Enter password: ";
                std::getline(std::cin, password);
                std::string decoded = hash_obj.Decode(name);
                if (password == decoded) {
                    std::cout << "Login successful.\n";
                } else {
                    std::cout << "Incorrect password.\n";
                }
            } else {
                std::cout << "User not found.\n";
            }
            system("sleep 1");
            system("clear");
        } else if (choice == 3) {
            break;
        } else {
            std::cout << "Invalid choice. Please try again.\n";
            system("sleep 1");
            system("clear");
        }
    }
}