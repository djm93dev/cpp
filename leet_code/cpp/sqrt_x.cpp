#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int ans = sqrt(x);
        return ans;
        
    }
};

int main()
{

    Solution s;
    cout << s.mySqrt(4) << endl;
    return 0;

}