#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <functional>

using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
        vector<int> v;
        while (n > 0) {
            v.push_back(n % 10); // % 10 to get the last digit
            n /= 10; // /= 10 to remove the last digit
        }
        int product = accumulate(v.begin(), v.end(), 1, multiplies<int>()); // 1 is the initial value
        int sum = accumulate(v.begin(), v.end(), 0); // 0 is the initial value
        return product - sum;
        
    }
};

int main()
{
    Solution s;
    int n = 234;
    int result = s.subtractProductAndSum(n);
    std::cout << result << std::endl;

}