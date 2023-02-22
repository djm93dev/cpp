#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
 
void print(std::vector<char> const& v, auto suffix)
{
    for (char c : v)
        std::cout << c << ' ';
    std::cout << suffix;
}
 
int main()
{
    std::vector<char> v1{'a', 'b', 'c', 'd'};
    std::vector<char> v2{'a', 'b', 'c', 'd'};
 
    for (std::mt19937 g{std::random_device{}()};
         !std::lexicographical_compare(v1.begin(), v1.end(),
                                       v2.begin(), v2.end());)
    {
        print(v1, ">= ");
        print(v2, '\n');
 
        std::shuffle(v1.begin(), v1.end(), g);
        std::shuffle(v2.begin(), v2.end(), g);
    }
 
    print(v1, "<  ");
    print(v2, '\n');
}