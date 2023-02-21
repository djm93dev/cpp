#include <iostream>
#include <iterator>
#include <string>
#include <regex>

// User Class
class User
{
public:
    User(std::string email, std::string password, std::string birthday)
        : email(email), password(password), birthday(birthday) {}

    std::string email;
    std::string password;
    std::string birthday;
};


// validate email address
bool validate_email(std::string email)
{
    std::regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return std::regex_match(email, pattern);
}

bool validate_password(std::string password)
{
    std::regex pattern("((?=.*\\d)(?=.*[a-z])(?=.*[A-Z])(?=.*[@#$%]).{6,20})");
    return std::regex_match(password, pattern);
}

bool validate_birthday(std::string birthday)
{
    std::regex pattern("(\\d{2})/(\\d{2})/(\\d{4})");
    return std::regex_match(birthday, pattern);
}

int main()
{
    // ask user for email, password, birthday and store them in a User object
    std::string email, password, birthday;
    std::cout << "Enter email: ";
    std::cin >> email;
    std::cout << "Enter password: ";
    std::cin >> password;
    std::cout << "Enter birthday: ";
    std::cin >> birthday;

    // validate email, password, birthday
    if (!validate_email(email))
    {
        std::cout << "Invalid email address" << std::endl;
        return 1;
    }
    if (!validate_password(password))
    {
        std::cout << "Invalid password" << std::endl;
        return 1;
    }
    if (!validate_birthday(birthday))
    {
        std::cout << "Invalid birthday" << std::endl;
        return 1;
    }
    // if all validations are passed, create a User object
    User user(email, password, birthday);
    std::cout << "User created successfully" << std::endl;
    // print user info
    std::cout << "Email: " << user.email << std::endl;
    std::cout << "Password: " << user.password << std::endl;
    std::cout << "Birthday: " << user.birthday << std::endl;
    return 0;
}