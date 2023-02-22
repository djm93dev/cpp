#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>
 
int main()
{
    std::string in = "1234567890";
    std::string out;
 
    std::copy_n(in.begin(), 4, std::back_inserter(out));
    std::cout << out << '\n';
    
    // copy_n with a vector
    std::vector<int> v_in(128);
    std::cout << "v_in: " << v_in.size() << '\n';
    std::iota(v_in.begin(), v_in.end(), 1);
    std::vector<int> v_out(v_in.size());
    std::cout << "v_out: " << v_out.size() << '\n';
    
    // copy the first 100 elements of v_in to v_out
    std::copy_n(v_in.cbegin(), 100, v_out.begin());
    // print the sum of the first 100 elements of v_out
    std::cout << std::accumulate(v_out.begin(), v_out.end(), 0) << '\n';
}