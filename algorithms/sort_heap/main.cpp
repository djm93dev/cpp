#include <algorithm>
#include <vector>
#include <iostream>
 
int main()
{
    std::vector<int> v = {3, 1, 4, 1, 5, 9};
 
    std::make_heap(v.begin(), v.end());
 
    std::cout << "heap:\t";
    for (const auto &i : v)
        std::cout << i << ' ';
 
    std::sort_heap(v.begin(), v.end());
 
    std::cout << "\nsorted:\t";
    for (const auto &i : v)
        std::cout << i << ' ';
    std::cout << '\n';
}