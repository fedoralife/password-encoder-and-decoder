# Hash Function Implementation in C++

This project implements a hash function in C++ for educational purposes. The hash function can be used for various applications such as hash tables, cryptographic applications, or data integrity checks.

# How it works

We have 3 option which are to create user, login user and exit the program as we are greeted.
Users information is stored on the hash table.


## Features

- Simple hash function implementation that converts the given string into a number.


## Prerequisites

- Linux with bash shell
- Make
- C++17 or later

## Building the Project

To build the project, use CMake. Follow these steps:

1. Clone the repository:
    ```sh
   git clone https://github.com/fedoralife/password-encoder-and-decoder.git
    ```

2. Go to The scripts folder and run the bash script run.sh it will automatically build the project and run it:
    ```sh
    cd Scripts
    bash run.sh
    ```

## Running the Tests

-- Use the make_file_for_test for you to run a test executable file.
1. First change  make_file_for_test.txt to maketestfile.
2. Then build it via make.
3. Finally run the test executable.


## How everything is done

- In the main method we just create user and login and exit.
- In the hash.cpp file we have an encoder and decoder which have encode and decode methoeds.
- The encode method is activated when user creates an account for the first time.
- It will then write it into a the hash_table.txt file.
- The decode method is activated when the user logins in.
- In the decoding we are going to read from the hash_table.txt file and check the credentials.
- If it matches it will sy login successful if not it will satate that it is invalid.

# Future Improvement

- Cross checking if a user exits or not.
- Add A graphical user interface which is a multi - cross platform.
- Integration with message apps and crypto coins.

