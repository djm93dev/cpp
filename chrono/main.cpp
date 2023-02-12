#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <algorithm>

using namespace std::chrono;

int main()
{
    // starting time
    auto old = steady_clock::now();

    // do something
    for(int i = 0; i < 1,000,000; ++i)
    {
        std::cout << "test" << std::endl;
    }

    // ending time
    auto duration = steady_clock::now() - old;

    // difference between starting and ending time
    auto dur = steady_clock::now() - old;

    std::cout << dur.count() << std::endl;




    return 0;
}