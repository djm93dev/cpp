#include <cstdio>
#include <locale>
#include <algorithm>
#include <string.h>

constexpr size_t _maxlen = 128;

int main() {
    char s[] = "big light in sky slated to appear in east";
    
    char lastc = 0;
    // std::transform( s, s + strnlen(s, _maxlen), s, [&lastc] (const char & c) -> char { // captured by reference
    // std::transform( s, s + strnlen(s, _maxlen), s, [=] (const char & c) mutable -> char { // captured by copy
    std::transform( s, s + strnlen(s, _maxlen), s, [=, &lastc] (const char & c) mutable -> char { // captured by copy and reference
        const char r = (lastc == ' ' || lastc == 0) ? toupper(c) : tolower(c);
        lastc = c;
        return r;
    } );
    puts(s);
    
    return 0;
}
