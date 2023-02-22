#include <regex>
#include <iostream>
 
int main()
{
    std::cout << std::regex_traits<char>::length(u8"Кошка") << '\n'
              << std::regex_traits<wchar_t>::length(L"Кошка") << '\n';
}