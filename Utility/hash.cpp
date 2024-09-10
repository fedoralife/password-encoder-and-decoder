
#include <fstream>
#include <sstream>
#include <iostream>
#include <cctype>

#include "hash.h"

const int SHIFT = 5; // shift number of bytes

int hash::Encode(const std::string& key, const std::string& name) {
    std::ofstream file("hash_table.txt", std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Error opening hash_table.txt" << std::endl;
        return -1;
    }
    file << name << ": ";  // Store the name of the key at the beginning of each line

    // Encoding each character individually
    for (char c : key) {
        int encoded_char = static_cast<int>(c) + SHIFT;
        file << encoded_char << ' ';  // Store each encoded character separated by space
    }
    file << std::endl;  // End the line for this entry
    file.close();
    return 0;
}

std::string hash::Decode(const std::string& name) {
    std::ifstream file("hash_table.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening hash_table.txt" << std::endl;
        return "";
    }

    std::string line;
    std::vector<int> encoded_values;
    while (std::getline(file, line)) {
        size_t pos = line.find(':');
        if (pos != std::string::npos) {
            std::string stored_name = line.substr(0, pos);
            if (stored_name == name) {
                std::string values_str = line.substr(pos + 1);
                std::istringstream iss(values_str);
                int value;
                while (iss >> value) {
                    encoded_values.push_back(value);
                }
                break; // Stop searching once the name is found
            }
        }
    }
    file.close();

    // Decode the values
    std::string decoded_key;
    for (int encoded_char : encoded_values) {
        char decoded_char = static_cast<char>(encoded_char - SHIFT);
        if(isalnum(decoded_char) || ispunct(decoded_char)){
                decoded_key.push_back(decoded_char);
        }
        else{
            decoded_key.append(" "); // Add a space for non-alphanumeric characters
        }
        
    }

    return decoded_key;
}

bool hash::Login(const std::string& name) {
    std::ifstream file("hash_table.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening hash_table.txt" << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        size_t pos = line.find(':');
        if (pos != std::string::npos) {
            std::string stored_name = line.substr(0, pos);
            if (stored_name == name) {
                file.close();
                return true; // Name found
            }
        }
    }
    file.close();
    return false; // Name not found
}
