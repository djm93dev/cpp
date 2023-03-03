#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0; // initialize result
        while (n > 0) { // keep dividing n by powers of 5 and update count
            count += n / 5; // n/5 gives the number of trailing 0s in n!
            n /= 5; // keep dividing n by powers of 5
        }
        return count; // return result
        
    }
};

int main()
{
    Solution s;
    cout << s.trailingZeroes(3) << endl;
    cout << s.trailingZeroes(5) << endl;

    return 0;
}