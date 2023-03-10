#include <algorithm>
#include <chrono>
#include <iostream>
#include <iterator>
#include <list>
#include <thread>
#include <vector>
 
void f(int n)
{
    std::this_thread::sleep_for(std::chrono::seconds(n));
    std::cout << "thread " << n << " ended" << std::endl;
}
 
int main()
{
    std::vector<std::jthread> v;
    v.emplace_back(f, 1);
    v.emplace_back(f, 2);
    v.emplace_back(f, 3);
    std::list<std::jthread> l;
 
    // copy() would not compile, because std::jthread is noncopyable
    std::move(v.begin(), v.end(), std::back_inserter(l));
}