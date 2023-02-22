#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
 
//Copies the elements from the range [first, last), to another range beginning at d_first in such a way that there are no consecutive equal elements. 
//Only the first element of each group of equal elements is copied.

int main()
{
    std::string s1 = "The      string    with many       spaces!";
    std::cout << "before: " << s1 << '\n';
 
    std::string s2;
    std::unique_copy(s1.begin(), s1.end(), std::back_inserter(s2),
                     [](char c1, char c2){ return c1 == ' ' && c2 == ' '; });
 
    std::cout << "after:  " << s2 << '\n';
}