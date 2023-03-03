#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0; // create a unsigned 32 bit integer to store the result
        for (int i = 0; i < 32; i++) { // loop through the bits of the number
            res <<= 1; // shift the result to the left by 1 bit
            res |= n & 1; // add the last bit of the number to the result
            n >>= 1; // shift the number to the right by 1 bit
        }
        return res; // return the result
        
    }
};

int main()
{
    Solution s;
    cout << s.reverseBits(43261596) << endl;
    return 0;
}