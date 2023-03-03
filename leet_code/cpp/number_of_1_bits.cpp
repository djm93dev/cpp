#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0; // initialize the result
        while (n) { // loop through the bits of the number
            res += n & 1; // add the last bit of the number to the result
            n >>= 1; // shift the number to the right by 1 bit
        }
        return res; // return the result
        
    }
};

int main()
{
    Solution s;
    cout << s.hammingWeight(11) << endl;
    return 0;
}