#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
 
int main()
{
    const std::size_t sz = 4;
    std::allocator<std::string> alloc;
    std::string* p = alloc.allocate(sz);
 
    std::uninitialized_fill(p, p + sz, "Example");
 
    for (std::string* i = p; i != p + sz; ++i)
    {
        std::cout << *i << '\n';
        i->~basic_string<char>();
    }
 
    alloc.deallocate(p, sz);
}