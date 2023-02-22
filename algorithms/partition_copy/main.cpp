#include <algorithm>
#include <iostream>
#include <utility>
 
void print(auto rem, auto const& v)
{
    for (std::cout << rem; auto const& x : v)
        std::cout << x << ' ';
    std::cout << '\n';
}
 
int main()
{
    int arr [10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int true_arr [5] = {0};
    int false_arr [5] = {0};
 
    std::partition_copy(std::begin(arr), std::end(arr),
                        std::begin(true_arr), std::begin(false_arr),
                        [] (int i) { return 4 < i; });
 
    print("true_arr:  ", true_arr);
    print("false_arr: ", false_arr);
}