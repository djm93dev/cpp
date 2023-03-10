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
    // end line test
    for(int i = 0; i < 1,000,000; ++i)
    {
        std::cout << "test" << std::endl;
    }
    // ending time
    auto duration = steady_clock::now() - old;
    // difference between starting and ending time
    auto dur = steady_clock::now() - old;
    std::cout << dur.count() << std::endl;


    // new line test
    for(int i = 0; i < 1,000,000; ++i)
    {
        std::cout << "test" << "\n ";
    }
    // starting time
    auto old2 = steady_clock::now();
    // ending time
    auto duration2 = steady_clock::now() - old2;
    // difference between starting and ending time
    auto dur2 = steady_clock::now() - old2;
    std::cout << dur2.count() << std::endl;



    // test push back vector vs. insert vector
    std::vector<int> v;
    // starting time
    auto old3 = steady_clock::now();
    // push back test
    for(int i = 0; i < 1,000,000; ++i)
    {
        v.push_back(i);
    }

    // ending time
    auto duration3 = steady_clock::now() - old3;
    // difference between starting and ending time
    auto dur3 = steady_clock::now() - old3;
    std::cout << "push back: " << dur3.count() << std::endl;

    // starting time
    auto old4 = steady_clock::now();
    // insert test
    for(int i = 0; i < 1,000,000; ++i)
    {
        v.insert(v.begin(), i);
    }
    // ending time
    auto duration4 = steady_clock::now() - old4;
    // difference between starting and ending time
    auto dur4 = steady_clock::now() - old4;
    std::cout << "insert: " << dur4.count() << std::endl;



    // test copy vector vs. move vector
    std::vector<int> v2;
    // starting time
    auto old5 = steady_clock::now();
    // copy test
    for(int i = 0; i < 1,000,000; ++i)
    {
        std::vector<int> v3 = v2;
    }
    // ending time
    auto duration5 = steady_clock::now() - old5;

    // difference between starting and ending time
    auto dur5 = steady_clock::now() - old5;
    std::cout << "copy: " << dur5.count() << std::endl;

    // starting time
    auto old6 = steady_clock::now();
    // move test
    for(int i = 0; i < 1,000,000; ++i)
    {
        std::vector<int> v4 = std::move(v2);
    }
    // ending time
    auto duration6 = steady_clock::now() - old6;
    // difference between starting and ending time
    auto dur6 = steady_clock::now() - old6;
    std::cout << "move: " << dur6.count() << std::endl;


    



    return 0;


}