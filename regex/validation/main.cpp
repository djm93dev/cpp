#include <iostream>
#include <iterator>
#include <string>
#include <regex>

// validate email address
bool validate_email(std::string email)
{
    // require 1 upper, 1 lower, 1 digit, 1 special, 8-20 chars
    std::regex pattern("((?=.*\\d)(?=.*[a-z])(?=.*[A-Z])(?=.*[@#$%]).{8,20})");
    return std::regex_match(email, pattern);
    
}

bool validate_password(std::string password)
{
    std::regex pattern("((?=.*\\d)(?=.*[a-z])(?=.*[A-Z])(?=.*[@#$%]).{6,20})");
    return std::regex_match(password, pattern);
}

int main()
{
    std::string email;
    std::cout << "Enter email address: ";
    std::cin >> email;
    if (validate_email(email))
    {
        std::cout << "Valid email address" << std::endl;
    }
    else
    {
        std::cout << "Invalid email address" << std::endl;
    }

    std::string password;
    std::cout << "Enter password: ";
    std::cin >> password;
    if (validate_password(password))
    {
        std::cout << "Valid password" << std::endl;
    }
    else
    {
        std::cout << "Invalid password" << std::endl;
    }

    return 0;
}