#include <iostream>
#include <iterator>
#include <string>
#include <regex>

// validate email address
bool validate_email(std::string email)
{
    std::regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return std::regex_match(email, pattern);
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

    return 0;
}