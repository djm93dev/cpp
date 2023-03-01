#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        
        //Handling corner cases
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        if(dividend==INT_MIN && divisor==1) return INT_MIN;

        
        //Converting divisors and dividend to their positive values
        long int dd = abs(dividend), dv = abs(divisor);
        
        //Result Variables
        int res=0;
        while(dv<=dd) {
            long int mul=dv, tmp=1;
            while(mul<=dd-mul) {
                mul+=mul;
                tmp+=tmp;
            }
            res+=tmp;
            dd-=mul;
        }
        
        //Handling signs
        if (dividend < 0 ^ divisor < 0)
            return -res;
        else
            return res;
        
    }
};

int main()
{
    Solution s;
    cout << s.divide(10, 3) << endl;
    cout << s.divide(7, -3) << endl;
    return 0;
}