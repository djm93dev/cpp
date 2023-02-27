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
            v.push_back(n % 10);
            n /= 10;
        }
        int product = accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
        cout << product << endl;
        int sum = accumulate(v.begin(), v.end(), 0);
        cout << sum << endl;
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